
#include "../include/types.h"
#include "gpio.h"


int main() {
	//unsigned char data_arr[8];
	unsigned char data_full;
	//unsigned char data;	

	Optional data_arr[8];
	Optional data;

	gpio_pup_enable(M6812_PORTH);

	gpio_set_input_all_reg(SET_PIN_H);

	serial_printbinbyte(_io_ports[SET_PIN_H]);

	data_arr[0] = gpio_read_pin(M6812_PORTH, 0);
	data_arr[1] = gpio_read_pin(M6812_PORTH, 1);
	data_arr[2] = gpio_read_pin(M6812_PORTH, 2);
	data_arr[3] = gpio_read_pin(M6812_PORTH, 3);
	data_arr[4] = gpio_read_pin(M6812_PORTH, 4);
	data_arr[5] = gpio_read_pin(M6812_PORTH, 5);
	data_arr[6] = gpio_read_pin(M6812_PORTH, 6);
	data_arr[7] = gpio_read_pin(M6812_PORTH, 7);

	int i = 0;
	for (i = 0; i < 8; i++) {
		serial_printbinbyte(data_arr[i].data);
		serial_print("\n");
		serial_printbinbyte(data_arr[i].is_valid);
		serial_print("\n");
		serial_print("\n");
	}

	if (data.data == data_full) {
		serial_print("ok");
	} else {
		serial_print("bad");
	}
							

}
