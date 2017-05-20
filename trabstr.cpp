#include <iostream>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace Blacklib;

int main (int argc, char * argv[]){
	Blacklib button(GPIO_51,input,SecureMode);
	Blacklib sete0(GPIO_,output,SecureMode);
	Blacklib sete1(GPIO_,output,SecureMode);
	Blacklib sete2(GPIO_,output,SecureMode);
	Blacklib sete3(GPIO_,output,SecureMode);
	Blacklib sete4(GPIO_,output,SecureMode);
	Blacklib sete5(GPIO_,output,SecureMode);
	Blacklib sete6(GPIO_,output,SecureMode);
	
	while(true){
		while (button.getValue() != 1){}

		int dormi, unidade, dezena;
		
		srand(time(NULL));
		dormi = ((rand()%3+1)*1000);

		usleep(dormi);

		led.setValue(high);

		usleep(500);

		let.setValue(low):

		float cont=0;

		while(button.getValue() != 1){
			
			cont=cont+1;
			usleep(100);

		}
		
		unidade = cont%10;
		dezena = (cont/10)%10;
		
		
		switch(dezena)
		 {
			 case 0: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(high);
			 sete4.setvalue(high);
			 sete5.setvalue(high);
			 sete6.setvalue(low);break;
			 case 1: 
			 sete0.setvalue(low);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(low);
			 sete4.setvalue(low);
			 sete5.setvalue(low);
			 sete6.setvalue(low);break;
			 case 2: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(low);
			 sete3.setvalue(high);
			 sete4.setvalue(high);
			 sete5.setvalue(low);
			 sete6.setvalue(high);break;
			 case 3: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(high);
			 sete4.setvalue(low);
			 sete5.setvalue(low);
			 sete6.setvalue(high);break;
			 case 4
			 sete0.setvalue(low);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(low);
			 sete4.setvalue(low);
			 sete5.setvalue(high);
			 sete6.setvalue(high);break;
			 case 5: 
			 sete0.setvalue(high);
			 sete1.setvalue(low);
			 sete2.setvalue(high);
			 sete3.setvalue(high);
			 sete4.setvalue(low);
			 sete5.setvalue(high);
			 sete6.setvalue(high);break;
			 case 6: 
			 sete0.setvalue(high);
			 sete1.setvalue(low);
			 sete2.setvalue(high);
			 sete3.setvalue(high);
			 sete4.setvalue(high);
			 sete5.setvalue(high);
			 sete6.setvalue(high);break;
			 case 7: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(low);
			 sete4.setvalue(low);
			 sete5.setvalue(low);
			 sete6.setvalue(low);break;
			 case 8: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(high);
			 sete4.setvalue(high);
			 sete5.setvalue(high);
			 sete6.setvalue(high);break;
			 case 9: 
			 sete0.setvalue(high);
			 sete1.setvalue(high);
			 sete2.setvalue(high);
			 sete3.setvalue(low);
			 sete4.setvalue(low);
			 sete5.setvalue(high);
			 sete6.setvalue(high);break;
		 }
		 
		
		
		 
		 usleep(4000);
	}
	
	
	
	return 0;
}
