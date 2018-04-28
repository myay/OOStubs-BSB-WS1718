/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Benutzerschnittstelle eines Threads.                                      */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

#include "thread/customer.h"
 
class Thread : public Customer {
private:
      Thread (const Thread &copy); // Verhindere Kopieren
public:
	// einfach an Konstruktor von Entrant weiterleiten
	Thread (void* tos): Customer(tos){}    
 };

#endif
