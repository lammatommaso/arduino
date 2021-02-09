#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>
#include<stdio.h>

#define BLINK_MS 100 // delay time in ms

int main()
{
    DDRB |= 0b00100000; 
    DDRD &= ~0b00000100; // sets port D 2 to input
    PORTD = 0b00000100; // activate input at port D pin 2

    unsigned char sensor_pressed = 0b00000100;

    bool touch_sensor(){return ((PIND & sensor_pressed) == 0b00000100);}
    

    while(true)
    {
        if(touch_sensor())
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

            PORTD &= ~0b00001000;
        }
    }
}