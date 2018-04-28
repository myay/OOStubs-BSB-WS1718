/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

class PIT
 {
private:
	//pit1 ctrl und zaehler0
	// initialisieren um in das Steuerregister (8 bit) und in Port1 (16 bit) zu schreiben
	IO_Port ctrl_reg;
	IO_Port counter0;


    PIT(const PIT &copy); // Verhindere Kopieren
	// Kopie von... TODO 
	int interv;
public:
	// 0x40 ist der erste Speicherblock des ersten PIT, 0x43 für das Steuerregister
    PIT (int us) : ctrl_reg(0x43), counter0(0x40) {      
	interval (us);
    }
	// eingestelltes Unterbechungsintervall zurückgeben
    int interval ();
	// Unterbrechungsintervall neu einstellen
    void interval (int us);
};

#endif
