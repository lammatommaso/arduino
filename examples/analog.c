#include<avr/io.h>
#include<avr/interrupt.h>

double duty_cycle = 0;

ISR(TIMER0_OVF_vect) // ADC conversion completed
{
    OCR0A = duty_cycle;
}

void start_conversion()
{
    ADCSRA |= 0b01000000;
}

ISR(ADC_vect) // ADC conversion completed
{
    duty_cycle = ADC;
    start_conversion(); // restart conversion manually
}

void setupADC()
{
    // We need to set the reference voltage to V_cc
    ADMUX |= 0b01000000;
    // We need to tell which ADC we are using 
    ADMUX |= 0b00000101; // ADC5
    // Also ADLAR is set to 0

    // Enable ADC
    ADCSRA |= 0b10000000;
    // ADC Interrupt Enable
    ADCSRA |= 0b00001000;
    // Interrupt when finishes the conversion
    // One has to restart it manually
    //Set the clock prescaler to set the ADC time, now we set it to 128
    ADCSRA |= 0b00000111;
    // Disable digital input on the pin
    DIDR0 |= 0b00100000;

    start_conversion();
}

int main()
{
    // We are using PC5 for the analog input which is labelled with ADC5
    // ADC = (V_in*1024)/V_ref since it is a 10bit ADC
    DDRD |= 0b01000000;

    TCCR0A |= 0b10000000;
    TCCR0A |= 0b00000011; 
    TIMSK0 |= 0b00000001;

    setupADC();

    SREG = 0b10000000;

    TCCR0B |= 0b00000001;
    
    while(1)
    {
        
    }
    return 0;
}