/* $Id$ */
#include "device/cgastr.h"
//#include "device/panic.h"
//#include "device/keyboard.h"
#include "syscall/guarded_keyboard.h"

#include "machine/pic.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"

#include "guard/guard.h"

#include "user/appl.h"
#include "user/appl_g_keyb.h"

//#include "syscall/guarded_scheduler.h"// später entfernen
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_buzzer.h"

#include "machine/toc.h"
#include "thread/kickoff.h"
#include "thread/coroutine.h"

#include "device/watch.h"

#include "meeting/waitingroom.h"
Waitingroom waitingroom;

//#include "syscall/guarded_buzzer.h"
//Guarded_Buzzer buzzer;
#include "meeting/bellringer.h"
Bellringer bellringer;

CPU cpu;
PIC pic;
Plugbox plugbox;
Guard guard;

//Guarded_Scheduler scheduler;//später entfernen
Guarded_Organizer organizer;
Guarded_Semaphore semaphore(1);

CGA_Stream kout;
Guarded_Keyboard keyboard;

#define stack_size 4096

void* stack1[stack_size];
void* stack2[stack_size];
void* stack3[stack_size];
void* stack4[stack_size];
void* stack5[stack_size];
void* stack_idle[stack_size];
Idle idle(&stack_idle[stack_size]);
//void* tos_1 = &stack1[stack_size];
//void* tos_2 = &stack2[stack_size];
//void* tos_3 = &stack3[stack_size];
//void* tos_4 = &stack4[stack_size];
	
Application appl1(&stack1[stack_size], 1);
Application appl2(&stack2[stack_size], 2);
Application appl3(&stack3[stack_size], 3);
Application appl4(&stack4[stack_size], 4);

Application_GKB appl_gkb(&stack5[stack_size]);

//zum testen von toc_settle, toc_go und toc_switch
//extern "C" void toc_go (struct toc* regs, void *coroutine);
//extern "C" void toc_switch (struct toc* regs_now, struct toc* reg_then, void *coroutine);
//extern "C" void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*));

int main(){
	// epilogebene
	guard.enter();
	// main darf von Interrupts unterbrochen werden
	keyboard.plugin();
	cpu.enable_int();
	kout << "main enable int"<< endl;
	kout << "pic keyboard " << (int)pic.is_masked(PIC::keyboard) << endl;
	kout.flush();
	
	//kctrl.set_repeat_rate(30,0);
	//kout.setpos(5,1);
	
	/*
	kout << "pic mask 0 : " << (int)pic.is_masked(PIC::timer) << endl;
	kout << "pic mask 1 : " << (int)pic.is_masked(PIC::keyboard) << endl;
	kout << 0 << endl;
	kout.flush();
	return 0;
	*/
	//Application_GKB  a =  appl_gkb(&stack4[stack_size]);
	organizer.Scheduler::ready(appl_gkb);
	//organizer.Scheduler::ready(appl1);
	organizer.Scheduler::ready(appl2);
	//organizer.Scheduler::ready(appl3);
	//organizer.Scheduler::ready(appl4);
	kout << "keyboard " << &keyboard << endl;

	kout << "appl1 " << &appl1 << endl;
	kout << "appl_gkb " << &appl_gkb << endl;
	kout.flush();
	//scheduler.Scheduler::schedule();
	

	Watch w(10000); // hier in mikrosek
	w.windup();	

	organizer.schedule();

	return 0;


	

	//appl2.go();
	//appl2.resume(appl1);

	//void* tos1[256];
	//Application appl=Application(tos1);
	//Key key;
	//while(1){

		//kout.setpos(0,0);
		//kout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		//kout.flush();		


		//keyboard.trigger();
		//key = keyboard.key_hit();
		//if(key.valid()){
		//	kout << key.ascii();
		//	kout.flush();
		//}
	//}
	kout << "terminiert" << endl;
	kout.flush();
	      	                 
 
   return 0;
 }
