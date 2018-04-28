/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "machine/cpu.h"
#include "guard/guard.h"
#include "guard/locker.h"
#include "guard/secure.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* GLOBALE VARIABLEN */

//#include "thread/scheduler.h"
//#include "syscall/guarded_scheduler.h"
//extern Guarded_Scheduler scheduler;

#include "syscall/guarded_semaphore.h"
extern Guarded_Semaphore semaphore;

#include "syscall/guarded_organizer.h"
extern Guarded_Organizer organizer;
extern CGA_Stream kout;
extern CPU cpu;
extern Guard guard;

//extern Waitingroom waitingroom;
extern Application appl1;
extern Application appl2;
extern Application appl3;
extern Application appl4;
extern Bellringer bellringer;

Guarded_Buzzer buzz;

void wait()
{
	int i = 90000000;	
	while(i > 0)
	{
		i--;	
	}
}

void Application::action (){
	kout << "appl guard avail" << guard.avail() << endl;
	kout.flush();
	//Secure sercure;

	while(1);/*{
		if(!guard.avail()){
			kout << "!guard.avail" << endl;
			kout.flush();
			cpu.halt();
		}
	}*/
	{
	wait();

	if( (zahl % 1) == 0 ){
		semaphore.p();
		kout << "Thread " << id << " : " << zahl << endl;
    	kout.flush();
		semaphore.v();
	}
	// TODO: freiwillige Abgabe der CPU

	if ( id == 2 && zahl ==1){
		semaphore.p();
		kout << "Thread " << id << " block sich "<< endl;
		kout.flush();
		semaphore.v();
		Secure sercure;
		organizer.block(appl2 ,buzz);
	}

	if ( id == 4 && zahl == 7){
		semaphore.p();
		kout << "Thread " << id << " block sich "<< endl;
		kout.flush();
		semaphore.v();
		Secure sercure;
		organizer.block(appl4 ,buzz);
	}
		
	/*if(id==3 && zahl== 4){
		semaphore.p();
		kout << "Thread " << id << " wakeup thread 2 "<< endl;
		kout.flush();
		semaphore.v();
		Secure sercure;
		//organizer.wakeup(appl2);
	}*/

	if( id == 3 && zahl >= 5){
		semaphore.p();
		kout << "Thread " << id << " exit "<< endl;
		kout.flush();
		semaphore.v();
		organizer.exit();
		//cpu.halt();
	}

	/*if(id == 1 && zahl == 7){
		kout << "Thread " << id << " killt thread 2 "<< endl;
		organizer.kill(appl2);
		//return;
	}*/
	if(id == 1 && zahl == 15){
		kout << "Stelle buzzer mit 1" << endl;
		kout.flush();		
		buzz.set(5);
		bellringer.job(&buzz, 5);
	}

	zahl++;
	//scheduler.resume();
	}
    
	while(1){}

 
 }
