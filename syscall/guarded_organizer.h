/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ O R G A N I Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

#ifndef __Guarded_Organizer_include__
#define __Guarded_Organizer_include__


#include "thread/organizer.h"
#include "syscall/thread.h"

#include "guard/secure.h"
        
class Guarded_Organizer : public Organizer
 {
private:
      Guarded_Organizer (const Guarded_Organizer &copy); // Verhindere Kopieren
public:
      Guarded_Organizer () {}


	void ready (Thread& that);
	void exit ();
	void kill (Thread& that);
	void resume ();




/* Hier muesst ihr selbst Code vervollstaendigen */ 
 };

#endif
