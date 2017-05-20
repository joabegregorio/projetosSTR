#include  <time.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#include <sys/time.h> 
#include <sys/resource.h>
void carga(int k)
{
  float f = 0.999999;
  for(int i=0; i<k; i++)
    {
      f = f*f*f*f*f;
      f = 1.56;
        for(int j=0; j<k; j++)
           {
	     f = sin(f)*sin(f)*f*f*f;

            }
    }

}






int main ()
{


  pid_t pid1, pid2;     
  char *mensagem;    
   
  printf("Começando o programa atividade28 ... \n");
 // criar pai 1
  pid1 = fork();  
 
  	if(pid1 == 0){//filho 1
		carga(1000);
		pinodoled.setValue(high);
	}
	

	else {// pai 1
		pid2 = fork();
	
		if (pid2 == 0){// filho 2
			
			carga(1000);
			pinodoled.setValue(high);;
		} 	


		else{//final do pai
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
	}

		