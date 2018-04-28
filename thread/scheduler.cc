/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "thread/scheduler.h"
#include "machine/cpu.h"
extern CPU cpu;
#include "device/cgastr.h"
extern CGA_Stream kout;

//#include "machine/cpu.h"
//extern CPU cpu;


void Scheduler::ready (Entrant& that){
	//neuen prozess in die readyliste packen
	//cpu.disable_int();
	readylist.enqueue(&that);
	//cpu.enable_int();
}
void Scheduler::schedule (){
	kout << "--scheduler macht go" << endl;
	kout.flush();
	go(*(Entrant*)readylist.dequeue());

}
void Scheduler::exit (){
	kout << "--scheduler exit" << endl;
	kout.flush();
	//neuen prozesse scheduln, der alte prozess wird nicht in die readylist wieder eingefügt
	Entrant* temp = (Entrant*)readylist.dequeue();
	if(temp){
		//queue war nicht leer -> schedule den prozess der aus der ready liste genommen wurde
		dispatch(*temp);
	}else{
		//queue war leer -> führe idle prozess aus
		kout << "scheduler exit queue leer -> idle prozess" << endl;
		kout.flush();
		dispatch(idle);
	}
}
void Scheduler::kill (Entrant& that){
	kout << "--scheduler kill" << endl;
	kout.flush();
	//prozess aus der readyliste entfernen
	readylist.remove(&that);
}
void Scheduler::resume (){
	kout << "--scheduler resume" << endl;
	kout.flush();
	//aktiver prozess wird hinten in die readyliste gepackt | gilt nicht für idle prozess
	kout << "scheduler resume, active: " << ((Entrant*)active()) << " idle: " << &idle << endl;
	if((Entrant*)active() != &idle){
		readylist.enqueue((Entrant*)active());
	}
	
	//neuer prozess wird ausgeführt

	Entrant* temp = (Entrant*)readylist.dequeue();
	kout << "scheduler resume, temp: " << temp << " idle: " << &idle << endl;
	if(temp){
		//queue war nicht leer -> schedule den prozess der aus der ready liste genommen wurde
		dispatch(*temp);
	}else{
		//queue war leer -> führe idle prozess aus
		kout << "scheduler resume queue leer -> idle prozess" << endl;
		kout.flush();
		dispatch(idle);
	}
	
}
