/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Struktur toc dient dazu, bei einem Koroutinenwechsel die Werte der    */
/* nicht-fluechtigen Register zu sichern. toc_settle bereitet sie            */
/* entsprechend vor.                                                         */
/*****************************************************************************/

#include "machine/toc.h"

// TOC_SETTLE: bereitet den Kontext der Koroutine fuer den ersten
//             Aufruf vor.


void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*))
 {
	
	void** sp = (void**)tos;
	
	*(--sp) = (void*)kickoff;

	regs->rsp =  sp;
 }
