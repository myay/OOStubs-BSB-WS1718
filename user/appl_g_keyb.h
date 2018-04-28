/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_gkb_include__
#define __application_gkb_include__

#include "device/cgastr.h"
#include "thread/coroutine.h"
//#include "thread/entrant.h"
#include "syscall/thread.h"

#include "syscall/guarded_keyboard.h"

extern Guarded_Keyboard keyboard;
extern CGA_Stream kout;



class Application_GKB : public Thread
 {
private:
    Application_GKB (const Application_GKB &copy); // Verhindere Kopieren
    //int zahl;
	//int id;
public:                  	
    Application_GKB(void *tos) : Thread(tos){
		//id = 0;
		//zahl = 1;
	}
	/*Application(void *tos,int num) : Thread(tos){
		id = num;
		zahl = 1;
	}*/
    inline void action (){
		kout << "keyboard appl: " << guard.avail() << endl;
		kout.flush();
		//keyboard.plugin();
		while(1){
			//Key key = keyboard.getkey();
			//kout << key.ascii();
			//kout.flush();
		}
	}
 };

#endif
