/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
#include "device/panic.h"
/*
void Panic::trigger(){
	kout << "Panic: error";
	kout.flush();
	cpu.halt();
}*/

bool Panic::prologue(){
	kout << "Panic: error";
	kout.flush();
	cpu.halt();
	return false;
}
