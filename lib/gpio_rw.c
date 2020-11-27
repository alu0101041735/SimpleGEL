
#include "../include/sys/ports_def.h"


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define WRITE_ENABLED_PORT 0XFF

unsigned char gpio_read_port(unsigned char port) {
	unsigned char data = _io_ports[port];
	return data;
}

char gpio_write_port(int port, char data) {
	//Only allow to write to ports with all pins able to read
	int is_read_only = ((port == M6812_PORTAD0) ||
											(port == M6812_PORTAD1) ||
											(port == M6812_PORTE) ||
											(port == M6812_PORTCAN));

	if (is_read_only) {
		return EXIT_FAILURE;
	}

	//Check that the port is in write mode, if no return EXIT_FAILURE
	int is_write_enabled = 0;
	switch (port) {
		case M6812_PORTA:
			if (_io_ports[M6812_DDRA] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;

		case M6812_PORTG:
			if (_io_ports[M6812_DDRG] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;
			
		case M6812_PORTP:
			if (_io_ports[M6812_DDRP] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;
			
		case M6812_PORTH:
			if (_io_ports[M6812_DDRH] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;
			
		case M6812_PORTS:
			if (_io_ports[M6812_DDRS] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;
			
		case M6812_PORTT:
			if (_io_ports[M6812_DDRT] & WRITE_ENABLED_PORT ) {
				is_write_enabled = 1;
			} else {
			}
			break;
			
		default:
			return EXIT_FAILURE;
	}

	if (!is_write_enabled) {
		return EXIT_FAILURE;
	}
	_io_ports[port] = data;
	return EXIT_SUCCESS;
}
