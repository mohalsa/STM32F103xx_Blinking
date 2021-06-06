/*
     On-board LED BLINKIND SKETCH
     Green LED @ PC13
     By Mohammed Alsada 2021
     
     To start debugging:
     1- First run the tasr named "Allow debugging for any STM32F103xx MCU"
            by opening command palette chosing/typing Tasks: Run Task, then run it!
     2- Run debugging normaly.
*/

// ========= INCLUEDS =+=========
#include "stm32f1xx.h"
#include <stdio.h>


// ========= PROTOTYPES ===========
void portsInit(void);
void delay(uint32_t delay);


int main(void)
{
    portsInit();
    while(1)
    {
        GPIOC->ODR ^= GPIO_ODR_ODR13_Msk;
        delay(50000);
        
        GPIOC->ODR ^= GPIO_ODR_ODR13_Msk;
        delay(50000);
    }
}


void portsInit(void)
{
    // Enable clock to port "C" (Default SysCLK = 8Mhz)
    RCC->APB2ENR |= (1<<4);

    // Set PC13 MODE as Output @ 50Mhz (max). 
    GPIOC->CRH |= GPIO_CRH_MODE13_Msk;  
    // Setting Configuration for Pin PC13 CNF[1:0]
    GPIOC->CRH &= ~(GPIO_CRH_CNF13_Msk);

}   // End portsInit() Function.


void delay(uint32_t delay)
{
    for(uint32_t volatile i = 0; i < delay; i++)    // Volatile is used so no optimization is done to this variable "i"
    {
        // Loop doing nothing!
    }
}