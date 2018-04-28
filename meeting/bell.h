/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

/* Hier muesst ihr selbst Code vervollstaendigen */
#include "object/chain.h"
#include "device/cgastr.h"
extern CGA_Stream kout;

#include "machine/cpu.h"
extern CPU cpu;

class Bell : public Chain
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 {
private:
    Bell(const Bell &copy); // Verhindere Kopieren
	int counter;
public:
    Bell() {}

	inline void wait (int value){
		counter = value;
	}
	inline int wait (){
		return counter;
	}

	inline void tick (){
		if(!run_down()){
			counter--;
		}
		kout << "bell counter: " << counter << endl;
		kout.flush();
		//cpu.halt();
		
	}

	inline bool run_down(){
		return counter <= 0;
	}

	virtual void ring () = 0;

/* Hier muesst ihr selbst Code vervollstaendigen */ 

};

#endif
