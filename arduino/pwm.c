#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

double duty_cycle = 0;

ISR(TIMER0_OVF_vect) // Overflow vector
{
    OCR0A = (duty_cycle/100)*255;
}

int main()
{
    // Only pins labelled with OCnx support PWM
    // We are using PD6 labeled as OC0A
    DDRD |= 0b01000000;
    // We want the Fast PWM Mode where OC0A is cleared on match and set at BOTTOM
    // From 0 to compare it is 1 then it is set to 0 without clearing
    // the timer that shall only clear at overflow, this is a way to make
    // our own duty cycle
    TCCR0A |= 0b10000000;
    // For the mode we want the FAST PWM that has as TOP the overflow 0xFF
    TCCR0A |= 0b00000011; // could write them on the same line
    // This time we want the interrupt to occur at overflow
    TIMSK0 |= 0b00000001;
    // Now we set the prescaler (no prescaling)
    OCR0A = (duty_cycle/100)*255;// duty_cycle is the fraction of the overflow we want the pin to be on

    SREG = 0b10000000;// Before starting teh timer

    TCCR0B |= 0b00000001; // this actually starts the timer
    
    while(1)
    {
        _delay_ms(0.01);

        duty_cycle += 1;

        if(duty_cycle > 100)
        {
            duty_cycle = 0;
        }
    }
    return 0;
}