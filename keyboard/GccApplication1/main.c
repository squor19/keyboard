#include <avr/io.h>
#include <klawiatura.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	DDRA = 0xF0;
	PORTA = 0x0F;
	
    while (1) 
    {
		PORTC = getValueFromKeyboard();
    }
}
