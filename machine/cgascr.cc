/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
if(0<=x && x<=79 && 0<=y && y<=24){
  char *CGA_START = (char *)0xb8000;
  char *pos;
  pos = CGA_START + 2*(x+y*80);
  *pos = c;
  *(pos+1) = attrib;
}
}
void CGA_Screen::setpos (int x, int y){
  IO_Port index(0x3d4);
  IO_Port data(0x3d5);
	
  int pos;
  pos = (x+y*80);
  char high = pos >> 8;
  char low = pos & 0xff;
  index.outb(14); //high
  data.outb(high);
  index.outb(15); //low
  data.outb(low);
}
void CGA_Screen::getpos (int &x, int &y){
  IO_Port index(0x3d4);
  IO_Port data(0x3d5);
  index.outb(14); //high
  int high =  data.inb();
  index.outb(15); // low
  int low = data.inb();
  int pos = (high << 8) | low;
  x = (int) pos % 80;
  y = (int) pos / 80;
}


void CGA_Screen::print (char* text, int length, unsigned char attrib){
int x, y;

getpos(x,y);
for(int i = 0; i< length; i++){
	if( text[i] == '\n'){
		x=0;
		y++;
		if(y== 25){
			scroll(attrib);
			y--;
		}
	}else{
		show(x,y, text[i], attrib);
		if(x<79){
			x++;
		}else if(x==79){
			x=0;
			y++;
		}
		if(y== 25){
			scroll(attrib);
			y--;
		}//scrollfunktion
	}
  }
setpos(x,y);
}

void CGA_Screen::scroll(unsigned char attrib){
	char *CGA_START = (char *)0xb8000;
	char *pos;
	for(int x = 0; x< 80; x++){
		for(int y= 1; y < 25; y++){
			pos = CGA_START + 2*(x+y*80);
			//posOld = CGA_START + 2*(x+y*80);
			*(pos - 160) = *pos;
  			*(pos+1- 160) = *(pos+1); //attrib;
			if(y == 24){
				*pos = ' ';
				*(pos+1) = attrib; 
			}
		}
	}
	for(int i = 0; i < 80; i++){
		
	}
}



/* Hier muesst ihr selbst Code vervollstaendigen */ 
