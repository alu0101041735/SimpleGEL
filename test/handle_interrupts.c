
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

#define INTERRUPT_PIN_G M6812_KWIEG
#define INTERRUPT_PIN_H M6812_KWIEH




void gpio_set_interrupt_pin(int reg, int port)
{
	_io_ports[reg] |= 1UL << port;
}

void gpio_handle_interrupt()
{


}

void __attribute__((interrupt)) vi_kwgh(void)
{
	
	int reg;
	int port_g;
	int port;

	if (_io_ports[M6812_KWIFG] != 0x00) {

		port_g = 0;
		reg = _io_ports[M6812_KWIFG];

	}

	if (_io_ports[M6812_KWIFH] != 0x00) {

		port_g = 1;
		reg = _io_ports[M6812_KWIFH];

	}

	serial_print("\n");
	serial_printbinbyte(reg);
	serial_print("\n");


	switch (reg) {

		case (0x01):
			serial_print("port0\n");
			port = 0;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x02):
			serial_print("port1\n");
			port = 1;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x04):
			serial_print("port2\n");
			port = 2;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x08):
			serial_print("port3\n");
			port = 3;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x10):
			serial_print("port4\n");
			port = 4;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x20):
			serial_print("port5\n");
			port = 5;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x40):
			serial_print("port6\n");
			port = 6;
			_io_ports[reg] &= ~(1UL << port); 
			break;
		case (0x80):
			serial_print("port7\n");
			port = 7;
			_io_ports[reg] &= ~(1UL << port); 
			break;

		default:
			port = -1;
			break;
	}

	char c_port = (char) port;
	if (port_g == 0) {

		serial_print("Interrupción generada por el puerto G");
		serial_send(c_port);
		serial_print("\n");

	}
	else {
		serial_print("Interrupción generada por el puerto H");
		serial_send(c_port);
		serial_print("\n");

	}

	while (_io_ports[reg] != 0x00) {


	}

	serial_print("\nInterrupt ");

}

int main()
{

	lock();
	serial_print("\nInterrupt G register before set: ");
	serial_printbinbyte(_io_ports[INTERRUPT_PIN_G]);

	gpio_set_interrupt_pin(INTERRUPT_PIN_G, 0);

	serial_print("\nInterrupt G register after set: ");
	serial_printbinbyte(_io_ports[INTERRUPT_PIN_G]);

	unlock();

	while(1) {



	}


	return 0;
}
