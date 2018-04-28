/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/organizer.h"

#include "device/cgastr.h"
extern CGA_Stream kout;

void Organizer::block (Customer& customer, Waitingroom& waitingroom){
	//Prozess aus der Ready-liste entfernen und in einen Wartezimmer packen. Dem Prozess wird gesagt in welchem Wartezimmer er wartet.
	waitingroom.enqueue(&customer);
	customer.waiting_in(&waitingroom);
	kout << "organizer block " << endl;
	Scheduler::exit();//kill(customer);

}
void Organizer::wakeup (Customer& customer){
//der Prozess wird aus seinem Wartezimmer genommen und wieder in die Ready-liste gepackt. Er vergisst in welchen Wartezimmer er war bzw. das er überhaupt in einem Wartezimmer war. 
	Waitingroom *w =  customer.waiting_in();
	w->remove(&customer);
	customer.waiting_in(0);
	Scheduler::ready(customer);
}


void Organizer::kill (Customer& that){
	Waitingroom *w =  that.waiting_in();
	if(w==0){
		//wenn Prozess in ready-liste, dann killen.
		Scheduler::kill(that);
	}else{
		//Wenn der Prozess in einem Wartezimmer auf ein Ereigniss wartet, dann wird er aus dem Wartezimmer entfern. 
		w->remove(&that);
	}
	
}
