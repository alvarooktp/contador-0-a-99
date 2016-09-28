//*****************************************************************************
//		CONTADOR DE 0-99 CON DISPLAY 7 SEGMENTOS ANODO
//	Integrantes:
//		Rudy Sanchez, Andrea Ortiz y Alvaro Gomez
//
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
//#include "C:/ti/TivaWare_C_Series-2.1.3.156/inc/tm4c1294ncpdt.h"


//función que saca por el puerto K lo que se va a desplegar en el display

void desplegardecenas(int decenas){
	switch (decenas){
	    	case 0:
	    		//se podria direccionar directamente al puerto usando GPIO_PORTK_DATA_R = direccion;
	    	    GPIOPinWrite(GPIO_PORTK_BASE,
	    	        					(GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
										(0x0 | 0x0 | 0x0 | 0x0 | 0x0 | 0x0 | GPIO_PIN_6));
	    		break;
	    	case 1:
	    	    GPIOPinWrite(GPIO_PORTK_BASE,
	    	        					(GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
										(GPIO_PIN_0 | 0x0 | 0x0 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6));
	    		break;
	    	case 2:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    	        		(GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    					(0x0 | 0x0 | GPIO_PIN_2 | 0x0 | 0x0 | GPIO_PIN_5 | 0x0));
	    		break;
	    	case 3:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	    (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    		(0x0 | 0x0 | 0x0 | 0x0 | GPIO_PIN_4 | GPIO_PIN_5 | 0x0));
	    		break;
	    	case 4:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(GPIO_PIN_0 | 0x0 | 0x0 | GPIO_PIN_3 | GPIO_PIN_4 | 0x0 | 0x0));
	    		break;
	    	case 5:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(0x0 | GPIO_PIN_1 | 0x0 | 0x0 | GPIO_PIN_4 | 0x0 | 0x0));
	    		break;
	    	case 6:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(0x0 | GPIO_PIN_1 | 0x0 | 0x0 | 0x0 | 0x0 | 0x0));
	    		break;
	    	case 7:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(0x0 | 0x0 | 0x0 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | 0x0));
	    		break;
	    	case 8:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(0x0 | 0x0 | 0x0 | 0x0 | 0x0 | 0x0 | 0x0));
	    		break;
	    	case 9:
	    		GPIOPinWrite(GPIO_PORTK_BASE,
	    		    		    	        (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6),
	    		    		    			(0x0 | 0x0 | 0x0 | GPIO_PIN_3 | GPIO_PIN_4 | 0x0 | 0x0));
	    		break;
	    	}

}
int main(void)
{
    volatile uint32_t ui32Loop2; //Contador para esperar tiempo
    volatile uint32_t ui32Loop3; //Contador para esperar tiempo

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK); //activar el puerto K
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); //activar el puerto A

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK))  //Esperar 5 ciclos del reloj
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))  //Esperar 5 ciclos del reloj
    {
    }


    // Enable the GPIO K and A. Set the direction as output, and enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 );
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_0);


    int decenas= 0,unidades=0;
    // Loop forever.
    while(1) {

        	for(ui32Loop2 = 0; ui32Loop2 < 900; ui32Loop2++){

            	GPIOPinWrite(GPIO_PORTK_BASE,GPIO_PIN_7,GPIO_PIN_7);	//acti display der
            	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_0,0x0);			//desac display izq
            	desplegardecenas(unidades);

            	for(ui32Loop3 = 0; ui32Loop3 < 300; ui32Loop3++){} //esperar tiempo

        		GPIOPinWrite(GPIO_PORTK_BASE,GPIO_PIN_7,0x0);			//desac display der
            	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_PIN_0);	//activar display izq
            	desplegardecenas(decenas);

            	for(ui32Loop3 = 0; ui32Loop3 < 300; ui32Loop3++){} //esperar tiempo

        	}
        	unidades++;
        	if (unidades == 10){  //si ya se llegó a 10 entonces re iniciar unidades y aumentar decenas
        	  decenas++;
        	  unidades=0;

        	  if(decenas ==10){	//si ya se llegó a 10 entonces reiniciar decenas
        	    decenas = 0;
        	   }
        	}
    }
}
