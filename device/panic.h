/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */
#include "machine/cpu.h"
#include "device/cgastr.h"

#include "guard/gate.h"


extern CGA_Stream kout;
extern CPU cpu;


class Panic : public Gate{
private:
    Panic (const Panic &copy); // Verhindere Kopieren
public:
    Panic (){}

	//void trigger();
	bool prologue();        
          
 };

#endif

