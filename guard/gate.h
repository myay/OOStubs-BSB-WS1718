/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "device/cgastr.h"
#include "object/chain.h"

class Gate : public Chain{
private:
	bool in_q;
public:
	
	Gate(){
		in_q = false;
	}
	//virtual void trigger() = 0;

	virtual bool prologue () =0; //{return true;}
	virtual void epilogue () {}
	inline void queued (bool q) {
		in_q = q;
	}
	inline bool queued (){
		return in_q;
	}




};

                
#endif
