/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/
#include "device/cgastr.h"
/* INCLUDES */
#include "device/panic.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "guard/guard.h"
/* FUNKTIONEN */
extern Plugbox plugbox;
extern CPU cpu;
extern Guard guard;
extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian (unsigned int slot){
	
	//if(slot == 33) return;
	//CGA_Stream kout;

	//kout << "guardian" << endl;
	//kout << "guardian slot " << slot << endl;
	//kout.flush();
	//cpu.halt();

	Gate &gate = plugbox.report(slot);
	// falls slot grösser als letztes element der plugbox, dann panic
	// wenn prolog true ausgibt
	guard.relay(&gate);


	//kout << "gateobject put in queue" << endl;
	//kout.flush();

	//gate.trigger();

}
