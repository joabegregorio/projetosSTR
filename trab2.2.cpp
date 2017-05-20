#include <time.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "BlackLib.h"
#include "Adc.h"
#include <sys/time.h> 
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"

#define UNIT_MS 1000;
#define UNIT_SEC 1000000;

using namespace std;
using namespace BlackLib;

BlackGPIO l1(GPIO_46,output, SecureMode);
BlackGPIO l2(GPIO_65,output, SecureMode);

static int n = 0;

void carga(int portaLed, int k)
{

	float f = 0.999999;
		for(int i=0; i<k; i++)
		{
			f = f*f*f*f*f;
			f = 1.56;
				for(int j=0; j<k; j++)
					{
						f = sin(f)*sin(f)*f*f*f;
						if (n%2 == 0){
							if (portaLed ==1)
							{
								l1.setValue(high);
							}else{
								l2.setValue(high);
							}
						}
						else{
							if (portaLed ==1)
							{
								l1.setValue(low);
							}else{
								l2.setValue(low);
							}
						}
					}
					n++;
		}

}

int main ()
{

	BlackADC *Adc0 = new ADC(AIN0);
	BlackADC *Adc1 = new ADC(AIN1);

	//BlackADC 	analog(AIN0);
	//BlackADC 	analog(AIN1);

  pid_t pid1, pid2;
  int tempo = 0;
  char *mensagem;
  float P1, P2 = 0;
  int PLed;

   
  printf("Começando o programa atividade2.2 ... \n");
  usleep(1000);
  // criar pai 1

  setpriority(PRIO_PROCESS, 0, 0);
  cout << "Valor prioridade pai: " << getpriority(PRIO_PROCESS, 0) << endl;

  pid1 = fork();  
 
  	switch(pid1){//filho 1

  	case -1 :
  		exit(1);
  	case 0:

  		while(1){
  			PLed =1;
  			carga(PLed, 500);
  			}
  	}

  	pid2 = fork();
  	switch(pid2){//filho 2

  	  	case -1 :
  	  		exit(1);
  	  	case 0:

  	  		while(1){
  	  			PLed =2;
  	  			carga(PLed, 500);
  	  			}
  	  	}
	//	carga(1000);
		//pinodoled.setValue(high);
	/*	else {// pai 1
		pid2 = fork();
	
		if (pid2 == 0){// filho 2
			
			carga(1000);
			pinodoled.setValue(high);
		} 	*/
  	while(1){

  		tempo = 500*UNIT_MS;
  		usleep(tempo);

  		valorP1 = Adc0->getFloatValue();
  		valorP2 = Adc1->getFloatValue();

  	if (valorP1 > 1){
  		setpriority(PRIO_PROCESS, pid1 , 5);
  		cout << "Prioridade L1: 5" << endl;
  	}else{
  		setpriority(PRIO_PROCESS, pid2 , 19);
  		cout << "Prioridade L1: 19" << endl;
  	}
  	if (valorP2 > 1){
  	  		setpriority(PRIO_PROCESS, pid2 , 5);
  	  		cout << "Prioridade L2: 5" << endl;
  	  	}else{
  	  		setpriority(PRIO_PROCESS, pid2 , 19);
  	  		cout << "Prioridade L2: 19" << endl;
  	  	}

  	}
exit(0);
}


/*		else{//final do pai
			setpriority(PRIO_PROCESS, getpid(),0);
			while(true){
				if(filho1.getNumericValue()>1000){
					setpriotity(PRIO_PROCESS, pid1, 5);
				}
				else {
					setpriority(PRIO_PROCESS, pid1, 19);
				}
				if(filho2.getNumericValue()>100){
					setpriotity(PRIO_PROCESS, pid2, 5);
				}
				else{
					setpriotity(PRIO_PROCESS, pid2, 19);
				}
				usleep(50000);
			}


		}	
	}*/

		

