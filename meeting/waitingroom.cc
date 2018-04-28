/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/
#include "meeting/waitingroom.h"
#include "syscall/guarded_organizer.h"
extern Guarded_Organizer organizer;

/* Hier muesst ihr selbst Code vervollstaendigen */ 

Waitingroom::~Waitingroom (){
	Customer* temp = (Customer*)(Queue::dequeue());
	while(temp){
		temp = (Customer*)(Queue::dequeue());
		organizer.Organizer::wakeup(*temp);
	}
}

void Waitingroom::remove (Customer* customer){
	Queue::remove(customer);
}

