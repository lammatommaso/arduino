#include<avr/io.h>
#include<avr/interrupt.h>

int interrupt_counter;

ISR(TIMER0_COMPA_vect)
{
    interrupt_counter++;
    if( interrupt_counter > 10)
    {
        PORTB ^= 0b00100000;
        interrupt_counter = 0; //really important!!!
    }
}

void main()
{
    interrupt_counter = 0;

    DDRB |= 0b00100000;
    PORTB = 0b00000000;
    
    TCCR0A = (1 << WGM01); // Set the 8-bit timer to CTC-mode( Clear Timer on Compare)
    // equivalent to TCCR0A = 0b00000010;
    TCCR0B = (1 << CS00) | (1 << CS02); // Set 1024 as prescaler
    // equivalent to TCCR0B = 0b00000101;

    // TCNT0 keeps the count
    // OCR0A and OCR0B are two possible comparisons
    // When the OCIE0A of TIMSK0 if set and the I-bit too , the interruot is enabled when OCR0A == TCNT0
    SREG = 0b10000000; // (it is the I-bit)
    OCR0A = 0b11111111; // Is the number I want to compare , 255 is the maximum for 8 bits
    TIMSK0 = (1 << OCIE0A);
    // equivalent to TIMSK0 = 0b00000010;
    // When interrupt occurs the OCF0A bit of TIFR0 is set to 1 ( it is the 0b00000010 )
    while(1)
    {
        //stuff
    }
}