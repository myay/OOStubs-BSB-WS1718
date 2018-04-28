/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Liste, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#ifndef __Bellringer_include__
#define __Bellringer_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "object/list.h"
#include "meeting/bell.h"
class Bellringer : public List
/* Hier muesst ihr selbst Code vervollstaendigen */ 
{
private:
   Bellringer(const Bellringer &copy); // Verhindere Kopieren
public:
   Bellringer() {}
/* Hier muesst ihr selbst Code vervollstaendigen */ 

	void check ();
	void job (Bell *bell, int ticks);

	void cancel (Bell *bell);
};

#endif
