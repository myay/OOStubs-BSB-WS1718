/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/bellringer.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern CPU cpu;

void Bellringer::check (){
	Bell* temp = (Bell*) first();
	Bell* del;	
	while(temp){
		temp->tick();
		if(temp->run_down()){
			kout << "RING" << endl;
			kout.flush();
			//cpu.halt();			
			temp->ring();
			del = temp;
			temp = (Bell*)temp->next;
			remove(del);
		}else{
			temp = (Bell*)temp->next;
		}
	}
}
void Bellringer::job (Bell *bell, int ticks){
	//effizienter implementieren
	bell->wait(ticks);
	enqueue(bell);
}
void Bellringer::cancel (Bell *bell){
	remove(bell);
}
