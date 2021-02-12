#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

#define BLINK_MS 1000 

int main()
{
    DDRB |= 0b00100001;
    DDRD &= ~0b00000100; // sets port D 2 to input
    PORTD &= 0b00000100;
    

    while(true)
    {
        if((PIND & 0b00000100) == 0b00000100)
        {
            PORTB &= ~0b00100000;
            PORTB ^= 0b00000001; // sets pin 5 of port B register to 1
            _delay_ms(BLINK_MS);
        }
        else 
        {
            PORTB &= ~0b00000001;
            PORTB ^= 0b00100000; // sets pin 5 of port B register to 1
            _delay_ms(BLINK_MS);
        }
    }
}