#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

#define BLINK_MS 1000 // delay time in ms

int main()
{
    DDRB |= 0b00100000; // DDRB reister controls the pin mode for port B, 
                        // for pin 5 is set to 1
                        // |= is a bitwise sum

    while(true)
    {
        PORTB ^= 0b00100000; // sets pin 5 of port B register to 1
        _delay_ms(BLINK_MS);
    }
}