/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine Koroutine, die vom Scheduler verwaltet wird.                         */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

#include "thread/coroutine.h"
#include "object/chain.h"

/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Entrant : public Coroutine, public Chain
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Entrant (const Entrant &copy); // Verhindere Kopieren
public:
	Entrant (void* tos) : Coroutine(tos) {}
	//void action (){}
/* Hier muesst ihr selbst Code vervollstaendigen */          
 };

#endif
