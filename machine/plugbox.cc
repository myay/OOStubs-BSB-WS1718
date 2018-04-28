/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "machine/plugbox.h"

Plugbox::Plugbox (){
	for(int i =0; i < 64; i++){
		arr[i] = &panic;
	}
}


void Plugbox::assign (unsigned int slot, Gate& gate){
	if(slot >= 0 && slot <64){
		arr[slot] = &gate;
	}
}
Gate& Plugbox::report (unsigned int slot){
	return *(arr[slot]);
}
