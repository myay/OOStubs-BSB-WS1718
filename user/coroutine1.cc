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

#include "user/coroutine1.h"
#include "machine/cpu.h"
#include "guard/guard.h"
#include "guard/locker.h"
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* GLOBALE VARIABLEN */

extern CGA_Stream kout;
extern CPU cpu;
extern Guard guard;
/* Hier muesst ihr selbst Code vervollstaendigen */ 

void Coroutine1::action (){
	//kout.setpos(0,0);
	kout << "Thread " << num1 <<" : "<< zahl << endl;
        kout.flush();
	zahl++;
	
 
 }
