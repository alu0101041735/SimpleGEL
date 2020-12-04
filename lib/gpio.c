/**
 * Librería E/S 
 * \file gpio.c
 * \author Daniel Paz Marcos
 * \author David Martín Martín
 * \date 02/12/20
 * Universidad de La Laguna
 **/

#include <gpio.h>

/**
 * Pone la flag de output a un pin, indicado en los define
 * */
void gpio_set_output(int reg, int port)
{
	_io_ports[reg] |= 1UL << port;
}

/**
 * Pone la flag de output a todos los pines de un tipo
 * */
void gpio_set_output_all_reg(int reg)
{
	_io_ports[reg] |= 0xFF;
}

/**
 * Pone el flag de input a un pin, indicado en los define
 * */
void gpio_set_input(int reg, int port)
{
	_io_ports[reg] &= ~(1UL << port); 
}


/**
 * Pone el flag de input a todos los pines de un tipo
 * */
void gpio_set_input_all_reg(int reg)
{
	_io_ports[reg] &= 0x00;
}


/**
 * Vector de interrupciones.
 * */
void (*interrupt[])(void) = {SR_G, SR_H};


/**
 * Función que activa un pin de interrupción, pasándole un registro y un número de puerto, definidos en la librería
 * */
void gpio_set_interrupt_pin(int reg, int port)
{
	_io_ports[reg] |= 1UL << port;
}

/**
 * Función que desactiva un pin de interrupción
 * */
void gpio_reset_interrupt_pin(int reg, int port)
{
	_io_ports[reg] &= ~(1UL << port); 
}

/**
 * Función que desactiva todos los pines de interrupción de un registro
 * */
void gpio_reset_all_pins(int reg)
{
	_io_ports[reg] &= 0x00; 
}

/**
 * Función que activa todos los pines de interrupción de un registro
 * */
void gpio_set_interrupt_all_pins(int reg)
{
    _io_ports[reg] |= 0xFF;
}


/**
 * Función que Maneja las interrupciones.
 * Es llamada al enviar una señal de interrupción por uno de los pines con su flag activada
 * */
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

                interrupt[SR_G]();
	}
	else {
                interrupt[SR_H]();
	}


}

