
#include "../include/types.h"
#include "../lib/gpio.h"
#include "../lib/gpio.c"


int main() {
	Optional data_arr[8];
	unsigned char data_full;
	Optional data;	

	gpio_pup_enable(M6812_PORTE);

	gpio_set_input_all_reg(SET_PIN_E);
	data_arr[0].data = gpio_read_pin(M6812_PORTE, 0);
	data_arr[1].data = gpio_read_pin(M6812_PORTE, 1);
	data_arr[2].data = gpio_read_pin(M6812_PORTE, 2);
	data_arr[3].data = gpio_read_pin(M6812_PORTE, 3);
	data_arr[4].data = gpio_read_pin(M6812_PORTE, 4);
	data_arr[5].data = gpio_read_pin(M6812_PORTE, 5);
	data_arr[6].data = gpio_read_pin(M6812_PORTE, 6);
	data_arr[7].data = gpio_read_pin(M6812_PORTE, 7);

	data_full = data_arr[0].data |
							data_arr[1].data << 1 |
							data_arr[2].data << 2 |
							data_arr[3].data << 3 |
							data_arr[4].data << 4 |
							data_arr[5].data << 5 |
							data_arr[6].data << 6 |
							data_arr[7].data << 7;

	data = gpio_read_port(M6812_PORTE);

	if (data.data == data_full) {
		serial_print("ok");
	} else {
		serial_print("bad");
	}
							

	

}
