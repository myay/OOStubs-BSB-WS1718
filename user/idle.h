/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __idle_include__
#define __idle_include__

//#include "device/cgastr.h"
//#include "thread/coroutine.h"
//#include "thread/entrant.h"
#include "syscall/thread.h"

#include "machine/cpu.h"
extern CPU cpu;

#include "device/cgastr.h"
extern CGA_Stream kout;


class Idle : public Thread
 {
private:
    Idle (const Idle &copy); // Verhindere Kopieren
public:                  	
    Idle(void *tos) : Thread(tos){}
    inline void action (){
		while(1){
			cpu.idle();
			kout << "idle" << endl;
			kout.flush();
		}
	}
 };

#endif
