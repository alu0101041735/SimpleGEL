
#include "../include/sys/ports_def.h"


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define WRITE_ENABLED_PORT 0XFF
#define READ_ENABLED_PORT 0X00

typedef struct Optional {
	char is_valid;
	unsigned char data;
} Optional;

Optional gpio_read_port(int port) {
	Optional data;
	if (port == M6812_PORTCAN) {

		data.is_valid = 0;
		data.data = 0;
		return data;
	}

	int read_mode_enabled;

	switch (port) {
		case M6812_PORTA:
			read_mode_enabled = ~(_io_ports[M6812_DDRA] | READ_ENABLED_PORT);
			break;
		case M6812_PORTB:
			read_mode_enabled = ~(_io_ports[M6812_DDRB] | READ_ENABLED_PORT);
			break;
		case M6812_PORTG:
			read_mode_enabled = ~(_io_ports[M6812_DDRG] | READ_ENABLED_PORT);
			break;
		case M6812_PORTH:
			read_mode_enabled = ~(_io_ports[M6812_DDRH] | READ_ENABLED_PORT);
			break;
		case M6812_PORTP:
			read_mode_enabled = ~(_io_ports[M6812_DDRP] | READ_ENABLED_PORT);
			break;
		case M6812_PORTS:
			read_mode_enabled = ~(_io_ports[M6812_DDRS] | READ_ENABLED_PORT);
			break;
		case M6812_PORTT:
			read_mode_enabled = ~(_io_ports[M6812_DDRT] | READ_ENABLED_PORT);
			break;
		case M6812_PORTAD0:
			read_mode_enabled = 1;
			break;
		case M6812_PORTAD1:
			read_mode_enabled = 1;
			break;
		case M6812_PORTE:
			read_mode_enabled = ~(_io_ports[M6812_DDRE] | READ_ENABLED_PORT);
			break;
		default:
			read_mode_enabled = 0;
			break;
	}

	if (read_mode_enabled) {
		data.is_valid = 1;
		data.data = _io_ports[port];
	} else {
		data.is_valid = 0;
		data.data = 0;
	}

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
