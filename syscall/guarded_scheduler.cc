/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

#include "syscall/guarded_scheduler.h"

// fast gleich wie Scheduler, locks in allen Funktionen verwenden 
// kann somit auf Epilogebene nicht von anderen Schedulerfunktionen unterbrochen werden

// anmelden
void Guarded_Scheduler::ready (Thread& that){
	Secure sec;
	Scheduler::ready(that);
}

// sich selbst beenden
void Guarded_Scheduler::exit (){
	Secure sec;
	Scheduler::exit();
}

// einen anderen Prozess beenden
void Guarded_Scheduler::kill (Thread& that){
	Secure sec;	
	Scheduler::kill(that);
}

// Prozesswechsel auslösen
void Guarded_Scheduler::resume (){
	Secure sec;
	Scheduler::resume();
}
