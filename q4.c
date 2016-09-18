#include <avr/io.h>
#include "cpu_speed.h"
#include <util/delay.h> 

int main(){
    set_clock_speed(CPU_8MHz);

    DDRB = 0b00001100;
    DDRD = 0b00000000;

    DDRF = 0b10011111;
    while(1){

        // Turn on left LED with left button (SW2)
        if((PINF  >> 5) & 0b1 ){

            PORTB = PORTB | 0b00001000;
            PORTB = PORTB & ~0b00000100;
        } 

        // Turn on right LED with right button (SW3)
        if((PINF  >> 6) & 0b1 ){

            PORTB = PORTB | 0b00000100;
            PORTB = PORTB & ~0b00001000;
        } 

        // Turn off both leds with down button (SWA)
        if ((PINB >> 7) & 0b1 ){

            PORTB = PORTB & ~0b00001100;
        }

        // Turn on both leds with up button (SWC)
        if ((PIND >> 1) & 0b1 ){

            PORTB = PORTB | 0b00001100;
        }

        // Toggle both leds with center button (SWCENTER)
        if ((PINB >> 0) & 0b1 ){
            _delay_ms(500);
            PORTB ^= 0b00001100;
        }
    }
return 0;
}