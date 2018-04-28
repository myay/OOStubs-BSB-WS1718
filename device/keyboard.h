/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "syscall/guarded_semaphore.h"
 
extern PIC pic;
extern Plugbox plugbox;
extern CGA_Stream kout;


class Keyboard : public Gate , public Keyboard_Controller {        
private:
    Keyboard (const Keyboard &copy); // Verhindere Kopieren
	Key key;
    Guarded_Semaphore semaphore;            
         
public:
	Keyboard(): semaphore(0){}
 
      // PLUGIN: 'Anstoepseln' der Tastatur. Ab sofort werden Tasten erkannt.
    void plugin ();

	bool prologue();
	void epilogue ();
	Key getkey ();
	//void trigger();
        
 };

#endif
