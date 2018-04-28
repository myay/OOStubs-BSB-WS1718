/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "device/cgastr.h"
#include "thread/coroutine.h"
//#include "thread/entrant.h"
#include "syscall/thread.h"




class Application : public Thread
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
    int zahl;
	int id;
public:                  	
    Application(void *tos) : Thread(tos){
		id = 0;
		zahl = 1;
	}
	Application(void *tos,int num) : Thread(tos){
		id = num;
		zahl = 1;
	}
    void action ();
 };

#endif
