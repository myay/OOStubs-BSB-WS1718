/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Locker implementiert eine Sperrvariable, die verwendet wird,   */
/* um kritische Abschnitte zu schuetzen. Die Variable zeigt allerdings nur   */
/* an, ob der kritische Abschnitt frei ist. Ein eventuelles Warten und der   */
/* Schutz der fuer diese Klasse notwendigen Zaehlfunktion muss ausserhalb    */
/* erfolgen.                                                                 */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

#include "device/cgastr.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern CPU cpu;

class Locker
 {
private:
    Locker(const Locker &copy); // Verhindere Kopieren
	bool locked;
public:
	Locker (){
		locked = false;
	}

	inline void enter (){
		kout << "Locker: enter" << endl;
		kout.flush();
		if(locked){
			kout << "Locker: kritischer abschnitt ist bereits belegt" << endl;
			kout.flush();
			cpu.halt();
		}

		//sperrt kritischen abschnitt
		locked = true;
	}
	inline void retne (){
		kout << "Locker: retne" << endl;
		kout.flush();
		if(!locked){
			kout << "Locker: kritischer abschnitt war schon frei" << endl;
			kout.flush();
			cpu.halt();
		}

		//gibt kritischen abschnitt wieder frei
		locked = false;
	}
	inline bool avail (){
		//gibt wieder ob der kritische abschnitt frei ist
		return !locked;
	}


 };

#endif
