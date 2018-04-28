/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "guard/guard.h"


void Guard::leave (){
	// prolog soll bei dequeue nicht unterbrechen dürfen		
	cpu.disable_int();
	Gate* item = (Gate*) q.dequeue();
	item->queued(false);
	cpu.enable_int();

	while(item != 0){
		// epilog erst ausführen
		// TODO: false setzen sollte auf prolog ebene stattfinden, zusammen mit dequeue
			
		item->epilogue ();
		// dequeue könnte von Enqueue unterbrochen werden
	
		cpu.disable_int();
		item = (Gate*) q.dequeue();	
		item->queued(false);
		cpu.enable_int();

	}
	retne();
}


void Guard::relay (Gate* item){
	//kout << "guard relay" << endl;
	kout.flush();
	if(item->prologue()){
		//kout << "guard relay, item.plologue == true" << endl;
		//kout.flush();

		//kritische abschnitt frei?
		if(avail ()){
			
			//kout << "lock is available" << endl;
			//kout << "item " << item << endl;
			kout.flush();
			
			// Epiloge nicht durch andere Epiloge unterbrechen						
			enter();
			// Epiloge dürfen durch Interrupts unterbrochen werden
			cpu.enable_int();
			kout << "-> epilogue" << endl;
			kout.flush();
			item->epilogue();
			kout << "<- epilogue" << endl;
			kout.flush();
			leave();
		
		//kritische abschnitt besetzt -> wenn item noch nicht in der queue dann packe item in queue
		}else if( !item->queued()){
			//cpu.disable_int();
			item->queued(true);		
			//cpu.enable_int();
	
			q.enqueue(item);
			kout << "queued" << endl;
			kout.flush();
		}
		else if(item->queued()) {
			kout << "already queued" << endl;
			kout.flush();
			cpu.halt();
		}
	}
	else {
		//kout << "no epilogue" << endl;
		//kout.flush();
	}
}
