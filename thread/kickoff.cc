/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Funktion zum Starten einer Koroutine.                                     */
/* Da diese Funktion nicht wirklich aufgerufen, sondern nur durch eine       */
/* geschickte Initialisierung des Stacks der Koroutine angesprungen wird,    */
/* darf sie nie terminieren. Anderenfalls wuerde ein sinnloser Wert als      */
/* Ruecksprungadresse interpretiert werden und der Rechner abstuerzen.       */
/*****************************************************************************/
#include "thread/coroutine.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/guard.h"

extern CGA_Stream kout;
extern CPU cpu;
extern Guard guard;

void kickoff(Coroutine* object){
	kout << "start kickoff" << endl;
	kout.flush();
	guard.leave();
	kout << object << endl;
	kout.flush();
	object->action();	
	kout << "Error: end of kickoff" << endl;
	kout.flush();
	while(1){}
}

