/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include "device/watch.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "meeting/bellringer.h"
extern CGA_Stream kout;
extern CPU cpu;
extern Bellringer bellringer;
// WINDUP: "zieht die Uhr auf". Danach laeuft sie los und loest in
//         regelmaessigen Abstaenden Unterbrechungen aus.
void Watch::windup (){
	//Timer in der Plugbox anmelden, zur Interruptvektortabelle hinzufügen
	//32 ist Interrupt Nummer des Timer-Bausteins
	plugbox.assign(Plugbox::timer, *this);
	//interrupts für timer erlauben
	pic.allow(PIC::timer);

}

// PROLOGUE: Prologue der Uhrenunterbrechung
bool Watch::prologue (){
	//kout << "Zähler prologue"<< endl;
	//kout.flush();
	//cpu.halt();
	counter++;
	if(counter % 100 == 0)
	{
		kout << "COUNTER: " << counter++ << endl;
		kout.flush();
		return true;
	}
	return false;
}

// EPILOGUE: Epilogue der Uhrenunterbrechung
void Watch::epilogue (){
	//prüfe ob glocken läuten müssen	
	// Prozesswechsel kann ausgeführt werden
		//kout << "watch epilog vor bellringer check"<< endl;
		//kout.flush();
		bellringer.check();		
		
		kout << "watch epilog vor scheduler resume"<< endl;
		kout.flush();		
		/*
		kout << "tick" << endl;
		kout << "                       tick" << endl;
		kout << "                       tick" << endl;
		kout << "                       tick" << endl;
		kout.flush();
		*/
		//kout << "COUNTER: " << counter++ << endl;
		//kout.flush();
		
		organizer.Scheduler::resume();

}
