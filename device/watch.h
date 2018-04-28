/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/pit.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

//#include "syscall/guarded_scheduler.h"
//extern Guarded_Scheduler scheduler;

#include "syscall/guarded_organizer.h"
extern Guarded_Organizer organizer;

extern Plugbox plugbox;
extern PIC pic;


class Watch : public Gate, public PIT
 {
private:
	int counter;
    Watch (const Watch &copy); // Verhindere Kopieren
public:
    // WATCH: Initialisiert die Uhr.
    Watch (int us) : PIT (us)
    {counter = 0;}

    // WINDUP: "zieht die Uhr auf". Danach laeuft sie los und loest in
    //         regelmaessigen Abstaenden Unterbrechungen aus.
    void windup ();

    // PROLOGUE: Prologue der Uhrenunterbrechung
    bool prologue ();

    // EPILOGUE: Epilogue der Uhrenunterbrechung
    void epilogue ();
 };

#endif
