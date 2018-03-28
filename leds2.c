#include <stdio.h>
#define LIM 700000

char* gpio_base = (char*) 0x91000000;

int main()
{
    printf("Rechnerarchitektur - de0_nano - light show starts...");
   
    unsigned char f=1;

    //set direction to all out
    *(gpio_base+1) = 0xff;
    *(gpio_base) = 1;

    int b = 1;
	
	for(;;){
		if(b){ 
		  (*gpio_base) <<= 1;
		  if(*(gpio_base) == 64){
		  	b = 0;
		  } 
		}
		else{
		*(gpio_base) = 1;
                 b=1;	
		}
		printf("%c",f+65);
      		for(int w=0; w<LIM; w++);
	}
}
