#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

int cli_flag;

ISR(INT1_vect)
{
    PORTB ^= 0b00100000;
    cli_flag = 1;
}

void main()
{
    DDRB |= 0b00100000;
    PORTB |= 0b00100000;
    // In case of INT or PCINT I don't need to set the DDRx to INPUT
    // Enable pull-up resistor for PD3
    PORTD |= 0b00001000; // PD3 is INT1
    
    // The pins labeled with INT can manage independent external interrupts
    // ISC11 and ISC10 choose 4 possible logic states for interrupt request at INT1
    EICRA &= 0b00001100; // I choose one
    // Enable interrupt request for INT1
    EIMSK |= 0b00000010;
    
    while(1)
    {
        // This thing eliminates bouncing (which idk)
        if(cli_flag == 0)
        {
            SREG |= 0b10000000;
        }
        else
        {
            SREG &= ~0b10000000;
            _delay_ms(500); // is always triggered blinks with 500ms delay
            cli_flag = 0;
        }
    }
}