/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "machine/pit.h"

void PIT::interval (int us){
	//unterbrechungsintervall neu einstallen
	//siehe PIT beschreibung

	// Kopie im Speicher halten um nicht immer auslesen zu müssen
	interv = us*1000; // in nanosekunden
	interv /= 838; // 838 mal pro nanosekunde

	//0x34 == 00 11 010 0 Modus 2 und erst niederwertiges dann höherwertiges Byte
	ctrl_reg.outb(0x34);

	int high, low;
	// niederwertiges byte
	low = interv & 0xff;
	// 8 bits shift
	high = interv >> 8; 
	// Anzahl ticks eintragen
	counter0.outb(low);
	counter0.outb(high);
}

int PIT::interval () {
	return interv;
}
