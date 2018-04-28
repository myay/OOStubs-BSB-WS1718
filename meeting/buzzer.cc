/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

/* INCLUDES */
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/buzzer.h"
#include "syscall/guarded_organizer.h"
extern Guarded_Organizer organizer;
#include "meeting/bellringer.h"
extern Bellringer bellringer;

#include "device/cgastr.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern CPU cpu;

Buzzer::~Buzzer(){
	destroy();
}
void Buzzer::destroy(){
	//Customer* temp;
	bellringer.cancel(this);
	Customer* customer = (Customer*)Queue::dequeue();
	while(customer){	
		organizer.wakeup(*customer);
		customer = (Customer*)Queue::dequeue();
	}
}

//schlafende threads aufwecken
void Buzzer::ring(){
	Customer* customer = (Customer*)Queue::dequeue();
	while(customer){
		kout << "bin in RING" << endl;
		kout.flush();	
		//cpu.halt();
		organizer.wakeup(*customer);
		customer = (Customer*)Queue::dequeue();
	}
}
void Buzzer::set (int ms){
	timer = ms;
}
void Buzzer::sleep (){
	Customer* customer = (Customer*)Queue::dequeue();
	while(customer){
		organizer.block(*customer, *this);
		customer = (Customer*)Queue::dequeue();
	}
}


