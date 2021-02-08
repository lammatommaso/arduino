#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

#define BLINK_MS 300 // delay time in ms

int main()
{
    DDRB |= 0b00100000; 
    PORTB = 0b00100000;
}