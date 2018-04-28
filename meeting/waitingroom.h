/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

#ifndef __waitingroom_include__
#define __waitingroom_include__


#include "object/queue.h"

#include "thread/customer.h"


//#include "syscall/guarded_organizer.h"
//sextern Guarded_Organizer organizer;


class Customer; // Forward declaration
//class Guarded_Organizer;

class Waitingroom 
 : public Queue
{
private:
    Waitingroom(const Waitingroom &copy); // Verhindere Kopieren

	//Organizer organizer;
public:
    Waitingroom() {}
	virtual ~Waitingroom ();
	virtual void remove (Customer* customer);

/* Hier muesst ihr selbst Code vervollstaendigen */ 
};

#endif
