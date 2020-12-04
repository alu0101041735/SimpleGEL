
#include <types.h>
#include "gpio.h"


int main() {
	unsigned char data_arr[8];
	unsigned char data_full;
	unsigned char data;	

	gpio_pup_disable_(M6812_PORTE);

	gpio_set_output_all_reg(SET_PIN_E);
	gpio_write_pin(M6812_PORTE, 0, 1);
	gpio_write_pin(M6812_PORTE, 1, 0);
	gpio_write_pin(M6812_PORTE, 2, 1);
	gpio_write_pin(M6812_PORTE, 3, 0);
	gpio_write_pin(M6812_PORTE, 4, 1);
	gpio_write_pin(M6812_PORTE, 5, 0);
	gpio_write_pin(M6812_PORTE, 6, 1);
	gpio_write_pin(M6812_PORTE, 7, 0);
}
