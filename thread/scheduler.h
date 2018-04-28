/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
#include "thread/entrant.h"
#include "object/queue.h"

#include "user/idle.h"

/* Hier muesst ihr selbst Code vervollstaendigen */ 

extern Idle idle;
//void* stack[1024];

class Scheduler : public Dispatcher
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    Scheduler (const Scheduler &copy); // Verhindere Kopieren
	Queue readylist;
	Entrant* runningTask;
	

public:
	Scheduler(){
		
	}
	void ready (Entrant& that);
    void schedule ();
    void exit ();
    void kill (Entrant& that);
    void resume ();
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
 };

#endif
