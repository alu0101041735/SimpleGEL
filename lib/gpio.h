
#include <stdio.h>
#include <types.h>
#include <sys/param.h>
#include <sys/interrupts.h>
#include <sys/sio.h>
#include <sys/locks.h>


/**
 * Pines permitidos
 **/
#define SET_PIN_S M6812_DDRS
#define SET_PIN_T M6812_DDRT
#define SET_PIN_G M6812_DDRG
#define SET_PIN_H M6812_DDRH
#define SET_PIN_S M6812_DDRS
#define SET_PIN_G M6812_DDRE 



/**
 * puertos de interrupción de la librería
 * */
#define INTERRUPT_PIN_G M6812_KWIEG
#define INTERRUPT_PIN_H M6812_KWIEH

/**
 * Subrutinas de interrupción para los pines G y H
 * */
#define SR_G 0xFFCE
#define SR_H 0xFFCF

