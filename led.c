#include <avr/io.h>
#include "cpu_speed.h"

int main(){
    set_clock_speed(CPU_8MHz);

    DDRB =  DDRB | 0b00000100;

    DDRF = DDRF & 0b11011111;
    while(1){
        if((PINF  >> 5) & 0b1 ){

            PORTB = PORTB | 0b00000100;

        }
    }
return 0;
}