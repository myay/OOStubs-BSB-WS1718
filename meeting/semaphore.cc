/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include "meeting/semaphore.h"
#include "device/cgastr.h"
extern Guarded_Organizer organizer;
extern CGA_Stream kout;

void Semaphore::p ()
{
	if ( counter > 0 )
	{	
		// Semaphore kann belegt werden
		counter--;	
	}
	else
	{
		// aktuell laufenden Prozess an die Warteliste anhängen und blockieren
		kout << "auf Sem Warteliste" << endl;
		kout.flush();
		organizer.Organizer::block(  *((Customer*)(organizer.Dispatcher::active())  ), *this);
	}

}

void Semaphore::v ()
{
	//kout << "semaphore v() counter:" << counter << endl;
	kout.flush();
	Customer* elem = (Customer*)Queue::dequeue();
	if( elem )
	{	
		kout << "aufwecken" << endl;
		kout.flush();
		// wenn mind. ein Customer auf Warteliste, dann wecke den ersten auf
		organizer.Organizer::wakeup( *elem );
		
	}
	else
	{
		// Zähler um eins erhöhen	
		counter++;
	}
}
