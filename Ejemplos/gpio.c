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


/*
 * #define PIN_A1 M6812_DDRA << 3 | 0x00
    8 #define PIN_A2 M6812_DDRA << 3 | 0x01
    7 #define PIN_A3 M6812_DDRA << 3 | 0x02
    6 #define PIN_A4 M6812_DDRA << 3 | 0x03
    5 #define PIN_A5 M6812_DDRA << 3 | 0x04
    4 #define PIN_A6 M6812_DDRA << 3 | 0x05
    3 #define PIN_A7 M6812_DDRA << 3 | 0x06
    2 #define PIN_A8 M6812_DDRA << 3 | 0x07
    1
  13  #define PIN 0x07
    1 #define REGISTRO ~0x00 >> 3

    */


void gpio_set_output(int reg, int port)
{
    reg >> 3;
    _io_ports[reg] |= port;

}


void gpio_set_input(int port)
{



}


int main()
{

    lock();

    char c[];
    unlock();
    c = serial_recv();

    gpio_set_output(M6812_PORTG, 2)



    return 0;
}
