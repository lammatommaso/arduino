#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define BUAD 9600
#define BRC BUAD/1000000-1

int main()
{
    UBRR0H = (BRC >> 8);
    UBRR0L = BRC;

    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 <<UCSZ00);

    while(1)
    {
        UDR0 = 'a';
        _delay_ms(1000);
    }

}