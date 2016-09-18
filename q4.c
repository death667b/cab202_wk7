#include <avr/io.h>
#include "cpu_speed.h"
#include <util/delay.h> 

int main(){
    set_clock_speed(CPU_8MHz);

    DDRB =  DDRB | 0b10001100;

    DDRF = DDRF & 0b10011111;
    while(1){
        if((PINF  >> 5) & 0b1 ){

            
            PORTB = PORTB | 0b00001000;

            

            PORTB =         0b00100100;
            PORTB = PORTB &~0b00000100;
                            0b11111011;

            PORTB =         0b11111011;
        } 

        if((PINF  >> 6) & 0b1 ){

            PORTB = PORTB | 0b00000100;
            PORTB = PORTB & ~0b00001000;
        } 

        if ((PINB >> 7) & 0b1 ){

            PORTB = PORTB | 0b00000000;
        }

        if ((PIND >> 1) & 0b1 ){

            PORTB = PORTB | 0b00001100;
        }


    }
return 0;
}