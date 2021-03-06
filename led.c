#include <avr/io.h>
#include "cpu_speed.h"
#include <util/delay.h> 

int main(){
    set_clock_speed(CPU_8MHz);

    DDRB =  DDRB | 0b00000100;

    DDRF = DDRF & 0b11011111;
    while(1){
        _delay_ms(500);
        PORTB = PORTB | 0b00000100;

        _delay_ms(500);
        PORTB = PORTB & 0b00000000;
    }
return 0;
}