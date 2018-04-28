/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "syscall/guarded_organizer.h"

void Guarded_Organizer::ready (Thread& that){
	Secure sec;
	Scheduler::ready(that);
}

// sich selbst beenden
void Guarded_Organizer::exit (){
	Secure sec;
	Scheduler::exit();
}

// einen anderen Prozess beenden
void Guarded_Organizer::kill (Thread& that){
	Secure sec;	
	Scheduler::kill(that);
}

// Prozesswechsel auslösen
void Guarded_Organizer::resume (){
	Secure sec;
	Scheduler::resume();
}
