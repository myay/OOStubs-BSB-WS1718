/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__

#include "meeting/waitingroom.h"
#include "syscall/guarded_organizer.h"
#include "thread/customer.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Semaphore : public Waitingroom
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Semaphore (const Semaphore &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
	int counter;


public:
	//Der Konstruktor initialisiert den Semaphorzähler mit dem angegebenen Wert c
	Semaphore (int c){
		counter = c;
	}
	
	//Warteoperation: Sofern der Semaphorzähler größer als Null ist, wird er nur um eins erniedrigt. Anderenfalls wird der aktuell laufende Prozess (ein Customer Objekt) an die Warteliste angefügt und blockiert.
	void p ();
	//Freigabeoperation: Wenn auf der Warteliste mindestens ein Customer eingetragen ist, wird der erste davon aufgeweckt. Anderenfalls wird der Semaphorzähler um eins erhöht.
	void v ();

	inline void wait (){
		p();
	}
	inline void signal (){
		v();
	}

 };

#endif
