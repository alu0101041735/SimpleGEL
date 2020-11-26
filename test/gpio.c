/* *******************************************
 * Libreria de E/S

 Daniel Paz Marcos
 David Martín Martín
 Universidad de La Laguna

 ******************************************* */

#include <stdio.h>
#include <types.h>
#include <sys/param.h>
#include <sys/interrupts.h>
#include <sys/sio.h>
#include <sys/locks.h>


#define SET_PIN_S M6812_DDRS
#define SET_PIN_T M6812_DDRT
#define SET_PIN_G M6812_DDRG
#define SET_PIN_H M6812_DDRH
#define SET_PIN_S M6812_DDRS
#define SET_PIN_G M6812_DDRE 

void gpio_set_output(int reg, int port)
{
	_io_ports[reg] |= 1UL << port;
}

void gpio_set_output_all_reg(int reg)
{
	_io_ports[reg] |= 0xFF;
}

void gpio_set_input(int reg, int port)
{
	_io_ports[reg] &= ~(1UL << port); 
}


void gpio_set_input_all_reg(int reg)
{
	_io_ports[reg] &= 0x00;
}


int main()
{
	serial_init();

	lock();

	unlock();
	gpio_set_output_all_reg(SET_PIN_G);
	serial_printbinbyte(_io_ports[SET_PIN_G]);

	gpio_set_input(SET_PIN_G, 2);
	serial_printbinbyte(_io_ports[SET_PIN_G]);




	return 0;
}
