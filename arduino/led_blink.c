#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

#define BLINK_MS 100 // delay time in ms

int main()
{
    DDRD |= 0b00100000; 
    DDRD |= 0b00010000;
    DDRD |= 0b00001000;

    while(true)
    {
        PORTD |= 0b00100000;
        PORTD &= ~0b00010000;
        PORTD &= ~0b00001000;
        _delay_ms(BLINK_MS);

        PORTD &= ~0b00100000;
        PORTD |= 0b00010000; 
        PORTD &= ~0b00001000;
        _delay_ms(BLINK_MS);

        PORTD &= ~0b00100000;
        PORTD &= ~0b00010000; 
        PORTD |= 0b00001000;
        _delay_ms(BLINK_MS);

        PORTD &= ~0b00100000;
        PORTD |= 0b00010000; 
        PORTD &= ~0b00001000;
        _delay_ms(BLINK_MS);
    }
}