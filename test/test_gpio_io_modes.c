
/**
 * Ejemplos de manejo de interrupciones para la librería E/S 
 * \file test_gpio_io_modes.c 
 * \author Daniel Paz Marcos
 * \author David Martín Martín
 * \date 02/12/20
 * Universidad de La Laguna
 **/

#include <gpio.h>
#include <sys/param.h>
#include <sys/ports.h>
#include <sys/interrupts.h>
#include <types.h>

/**
 * Programa de ejemplo
 * */
int main()
{


    gpio_set_output(SET_PIN_G, 1);
    gpio_set_output_all_reg(SET_PIN_S);


    return 0;
}
