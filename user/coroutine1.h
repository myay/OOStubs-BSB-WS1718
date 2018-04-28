/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __coroutine1_include__
#define __coroutine1_include__

#include "device/cgastr.h"
#include "thread/coroutine.h"

class Coroutine1 : public Coroutine
 {
private:
    Coroutine1 (const Coroutine1 &copy); // Verhindere Kopieren
    
public:                  
    int zahl;
    int num1;    
    Coroutine1(void *tos,int num) : Coroutine(tos),zahl(0),num1(num){

	}
    void action ();
 };

#endif
