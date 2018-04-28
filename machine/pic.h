/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__

#include "machine/io_port.h"


class PIC
 {
private:
    PIC(const PIC &copy); // Verhindere Kopieren

	IO_Port ocw1_master;
	IO_Port ocw1_slave;
public:
    PIC() : ocw1_master(0x21), ocw1_slave(0xa1) {};    
    enum {
    timer    = 0,
    keyboard = 1
    };
    void allow (int interrupt_device);
    void forbid (int interrupt_device);
    bool is_masked (int interrupt_device);

};

#endif
