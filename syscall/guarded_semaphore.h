/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#ifndef __Guarded_Semaphore_include__
#define __Guarded_Semaphore_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "guard/secure.h"
#include "meeting/semaphore.h"

class Guarded_Semaphore :public Semaphore
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Guarded_Semaphore (const Guarded_Semaphore &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
public:

	Guarded_Semaphore (int c) : Semaphore(c){}
	void p ();
	void v ();
	void wait ();
	void signal ();
 };

#endif
