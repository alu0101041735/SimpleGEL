//#include "pullup.h"
#include "../include/sys/ports_def.h"

#define PIN_A1 M6812_DDRA << 3 | 0x00 
#define PIN_A2 M6812_DDRA << 3 | 0x01 
#define PIN_A3 M6812_DDRA << 3 | 0x02 
#define PIN_A4 M6812_DDRA << 3 | 0x03 
#define PIN_A5 M6812_DDRA << 3 | 0x04 
#define PIN_A6 M6812_DDRA << 3 | 0x05 
#define PIN_A7 M6812_DDRA << 3 | 0x06 
#define PIN_A8 M6812_DDRA << 3 | 0x07 

#define PIN 0x07
#define REGISTRO ~0x00 << 3

//gpio_set_output(PIN_A1);
//gpio_set_output(M6812_DDRA, M6812B_DDA0);

//pin
//_io_ports[pin & REGISTRO >> 3]


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


int gpio_pup_enable(int reg) {
	int special_port = ((reg == M6812_PORTP) ||
											(reg == M6812_PORTS) || 
											(reg == M6812_PORTT) || 
											(reg == M6812_PORTCAN));


	if (!special_port) {
		//Enable pullup for ports A, B, E, G, H
		_io_ports[M6812_PUCR] |= reg;

	} else if (reg == M6812_PORTP){
		//Enable pup for port P
		_io_ports[M6812_PWCTL] |= 0x01 << 1;

	} else if (reg == M6812_PORTS){
		//Enable pup for port S
		unsigned char bits = _io_ports[M6812_PURDS];
		bits |= 0x07;
		_io_ports[M6812_PURDS] = bits;

	} else if (reg == M6812_PORTT){
		//Enable pup for port T
		_io_ports[M6812_TMSK2] |= 0x01 << 5;

	} else if (reg == M6812_PORTCAN){
		_io_ports[M6812_PCTLCAN] |= 0x02;
	} else {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int gpio_pup_disable_(int reg) {
	int special_port = ((reg == M6812_PORTP) ||
											(reg == M6812_PORTS) || 
											(reg == M6812_PORTT) || 
											(reg == M6812_PORTCAN));


	if (!special_port) {
		//Enable pullup for ports A, B, E, G, H
		_io_ports[M6812_PUCR] &= ~reg;

	} else if (reg == M6812_PORTP){
		//Enable pup for port P
		_io_ports[M6812_PWCTL] &= ~(0x01 << 1);

	} else if (reg == M6812_PORTS){
		//Enable pup for port S
		unsigned char bits = _io_ports[M6812_PURDS];
		bits &= ~0x07;
		_io_ports[M6812_PURDS] = bits;

	} else if (reg == M6812_PORTT){
		//Enable pup for port T
		_io_ports[M6812_TMSK2] &= ~(0x01 << 5);

	} else if (reg == M6812_PORTCAN){
		_io_ports[M6812_PCTLCAN] &= ~0x02;
	} else {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

