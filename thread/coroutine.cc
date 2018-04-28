/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Koroutinenkonzepts.                                   */
/* Im Konstruktor wird der initiale Kontext der Koroutine eingerichtet.      */
/* Mit go() wird die erste Koroutine aktiviert. Alle weiteren Koroutinen-    */
/* wechsel sollten mit resume() erfolgen.                                    */
/* Um bei einem Koroutinenwechsel den Kontext sichern zu koennen, enthaelt   */
/* jedes Koroutinenobjekt eine Struktur toc, in dem die Werte der nicht-     */
/* fluechtigen Register gesichert werden koennen.                            */
/*****************************************************************************/

#include "thread/coroutine.h"
#include "thread/kickoff.h"

#include "device/cgastr.h"

extern CGA_Stream kout;

// Funktionen, die auf der C- oder Assembler-Ebene implementiert werden,
// muessen als extern "C" deklariert werden, da sie nicht dem Name-Mangeling
// von C++ entsprechen.

extern "C" void toc_go (struct toc* regs, void *coroutine);
extern "C" void toc_switch (struct toc* regs_now, struct toc* reg_then, void *coroutine);
extern "C" void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*));

Coroutine::Coroutine(void* tos)
{
	toc_settle( &toc1, tos, (void(*)(void*))&kickoff );
	//kout << "settle finished" << endl;
	//kout.flush();
}
	
void Coroutine::go()
{
	toc_go (&toc1, this);
	//kout << "toc go finished" << endl;
	//kout.flush();
}
	
void Coroutine::resume(Coroutine& next)
{	
//	toc temp = next.toc1;
//	toc_switch(&toc1, &temp, &next);
	toc_switch(&toc1, &next.toc1, &next);
	//kout << "toc switch finished" << endl;
	//kout.flush();
}



