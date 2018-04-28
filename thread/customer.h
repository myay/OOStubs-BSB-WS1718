/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Thread, der auf ein Ereignis warten kann.                             */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include "thread/entrant.h"
#include "meeting/waitingroom.h"

class Waitingroom;
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Customer : public Entrant
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Customer (const Customer &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
	Waitingroom* wroom;

public:
	Customer (void* tos): Entrant(tos){
		wroom = 0;
	}

	//Mit dieser Methode wird im Customer vermerkt, dass dieser derzeit im Waitingroom w auf ein Ereignis wartet.
	inline void waiting_in (Waitingroom *w){
		wroom = w;
	}

	//Hiermit kann abgefragt werden, in welchem Waitingroom Objekt der Customer eingetragen ist. Ein Rückgabewert von 0 soll bedeuten, dass der Prozess auf überhaupt kein Ereignis wartet, also entweder der aktuell laufende Prozess ist, auf der Ready-Liste des Schedulers steht, bereits terminiert ist oder noch gar nicht beim Scheduler angemeldet wurde.
	inline Waitingroom* waiting_in (){		
		return wroom;
	}    
};

#endif
