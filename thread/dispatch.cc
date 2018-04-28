/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Dispatcher.                                           */
/* Der Dispatcher verwaltet den life-Pointer, der die jeweils aktive         */
/* Koroutine angibt. mit go() wird der life Pointer initialisiert und die    */
/* erste Koroutine gestartet, alle weiteren Kontextwechsel werden mit        */
/* dispatch() ausgeloest. active() liefert den life Pointer zurueck.         */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "thread/dispatch.h"

void Dispatcher::go (Coroutine& first){
	life_pointer = &first;
	first.go();

}
void Dispatcher::dispatch (Coroutine& next){
	//if(&next == life_pointer) return;
	Coroutine *temp = life_pointer;
	life_pointer = &next;
	temp->resume(next/*(*life_pointer)*/);
	
}
Coroutine* Dispatcher::active (){
	return life_pointer;
}
