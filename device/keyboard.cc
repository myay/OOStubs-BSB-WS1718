/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "device/keyboard.h"
#include "guard/locker.h"



void Keyboard::plugin (){
	//Keyboard in der Plugbox anmelden
	plugbox.assign(Plugbox::keyboard, *this);
		//interrupts für tastatur erlauben
	pic.allow(PIC::keyboard);

}

bool Keyboard::prologue(){
	kout << "keyboard prologue" << endl;
	kout.flush();

	key = key_hit();
	kout << "keyboard valid: " << key.valid() << endl;
	kout.flush();
	if(key.valid()){
		//ctrl + alt + del
		if(key.ctrl() && key.alt() && key.scancode()== 53){
			reboot();
			return false;
		}
		return true;
	}
	return false;
}
void Keyboard::epilogue (){
	
	//int x,y;
	//kout.getpos(x,y);
	//kout.setpos(10,10);
	
	kout << key.ascii();
	//kout.flush();
	//kout.setpos(x,y);
	kout << "keyboard epilogue" << endl;
	kout.flush();
	//guard.leave();
	semaphore.Semaphore::v();
}


Key Keyboard::getkey (){
	kout << "keyboard getkey" << endl;
	kout.flush();
	semaphore.Semaphore::p();
	return key;
}



/*
void Keyboard::trigger(){
	Key key = key_hit();
	if(key.valid()){
		//ctrl + alt + del
		if(key.ctrl() && key.alt() && key.scancode()== 53){
			reboot();
		}else{
			//tastendruck
			int x,y;
			kout.getpos(x,y);
			kout.setpos(10,10);
			kout << key.ascii();
			kout.flush();
			kout.setpos(x,y);
		}
	}
}
*/



