/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/
#include "machine/pic.h"
 
/* Interrupts müssen gespeichert werden, damit sie nicht verloren gehen 
 * z.B. mit dem Setzen eines Bit
 * Interrupt Mask Register: wenn nur ein Bit damm erlauben oder nicht erlauben.
 * OCW : Interrupt Control Word
 * ICW : Initialization Control Word 
 * IRQ : Interrupt Request
 * 
 */

#include "device/cgastr.h"
extern CGA_Stream kout;

void PIC::allow (int interrupt_device){
	//kout << "allow: " << interrupt_device << endl;
	int ocw1;

	if(interrupt_device > 7){
		ocw1 = ocw1_slave.inb();
		ocw1 &= ~(1 << (interrupt_device-8));
		ocw1_slave.outb(ocw1);
	}else{
		ocw1 = ocw1_master.inb();
		ocw1 &= ~(1 << interrupt_device);
		ocw1_master.outb(ocw1);
	}
	
	/*
	// Zugriff auf PIC über I/O Ports	
	// von Port 0x21 (Interrupt Mask Register, 8 bit) einlesen, 
	IO_Port ocw1_port(0x21);
	int ocw1, ocw1_tmp;
	
	//Einlesen und speichern des Inhaltes von Port 0x21 
	ocw1 = ocw1_port.inb();
	ocw1_tmp = ocw1;

	// interrupt_device == 0 ist System Timer 
	if ( interrupt_device == 0 && (ocw1%2) == 1 )
	{
		// erstes Interrupt Bit soll maskiert werde 
		ocw1=ocw1-1;
	}

	ocw1_tmp=ocw1/2;
	if ( (ocw1_tmp%2) == 1 && interrupt_device == 1 )
	{
		ocw1=ocw1-2;
	}
	ocw1_port.outb(ocw1);
	*/

}

void PIC::forbid (int interrupt_device){
	int ocw1;

	if(interrupt_device > 7){
		ocw1 = ocw1_slave.inb();
		ocw1 |=  (1 << (interrupt_device-8));
		ocw1_slave.outb(ocw1);
	}else{
		ocw1 = ocw1_master.inb();
		ocw1 |=  (1 << interrupt_device);
		ocw1_master.outb(ocw1);
	}

	/*
	IO_Port ocw1_port(0x21);
	int ocw1, ocw1_tmp;
	ocw1=ocw1_port.inb();
	ocw1_tmp=ocw1;
	if(interrupt_device==0 && (ocw1%2)==0){
		ocw1=ocw1+1;
	}
	ocw1_tmp=ocw1/2;
	if((ocw1_tmp%2)==0 && interrupt_device==1){
		ocw1=ocw1+2;
	}
	ocw1_port.outb(ocw1);
	*/
	
}

bool PIC::is_masked (int interrupt_device){

	int ocw1, b;

	if(interrupt_device > 7){
		b = (1 << (interrupt_device-8));
		ocw1 = ocw1_slave.inb();
		ocw1 &=  b;
		return (ocw1 == b);
	}else{
		b = (1 << interrupt_device);
		ocw1 = ocw1_master.inb();
		ocw1 &=  b;
		return (ocw1 == b);
	}



	/*
	IO_Port ocw1_port(0x21);
	int ocw1;
	ocw1=ocw1_port.inb();
	if(interrupt_device==0 && (ocw1%2)==1){
		return true;
	}
	if(interrupt_device==0 && (ocw1%2)==0){
		return false;
	}
	ocw1=ocw1/2;
	if((ocw1%2)==1 && interrupt_device==1){
		return true;
	}
	if((ocw1%2)==0 && interrupt_device==1){
		return false;
	}		 
	return false;
	*/
	
}

