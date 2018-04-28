/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"


O_Stream& O_Stream::operator<< (unsigned char c){
	put(c);
	return *this;
}
O_Stream& O_Stream::operator<< (char c){
	put(c);
	return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number){
	put_number((unsigned long) number);
    return *this;
}

O_Stream& O_Stream::operator<< (short number){
    if(number <0 && base==10){
		put('-');
		number *= (-1);
	}
	put_number((unsigned long) number);
    return *this;
}
 
O_Stream& O_Stream::operator<< (unsigned int number){	
	put_number((unsigned long) number);
    return *this;
}
 
O_Stream& O_Stream::operator<< (int number){
	if(number <0 && base==10){
		put('-');
		number *= (-1);
	}
	put_number((unsigned long) number);
    return *this;
}
 
O_Stream& O_Stream::operator<< (unsigned long number){
	put_number(number);
    return *this;
}

O_Stream& O_Stream::operator<< (long number){
	if(number <0 && base==10){
		put('-');
		number *= (-1);
	}
	put_number((unsigned long) number);
    return *this;
}



O_Stream& O_Stream::operator<< (void* pointer){
	int temp = base;
	base = 16;
	put_number((unsigned long) pointer);
	base = temp;
    return *this;
}


void O_Stream::put_number(unsigned long number){
	if(number == 0){
		put('0');
		return;
	}
	int len = 0;
	short ziffer[64];
	
	while(number !=0){
		ziffer[len] = number % (long)base;
		number /= (long)base;
		len++;
	}
	
	len--;
	for(int i = len; i>-1; i--){
		put( ziffer[i] < 10 ? '0' + ziffer[i] : 'a' + ziffer[i] -10);
		/*switch(ziffer[i]){
			case 0:
		         put('0'); break;             
	        case 1:
	            put('1'); break;
	        case 2:
                put('2');
              break;
	        case 3:
	            put('3');
	            break;
	        case 4:
	            put('4');
	            break;
	        case 5:
	            put('5');
	            break;
	        case 6:
	            put('6');
	            break;
	        case 7:
	            put('7');
	            break;
	        case 8:
	            put('8');
	            break;
	        case 9:
	            put('9');
	            break;
			case 10:
	            put('a');
	            break;
			case 11:
	            put('b');
	            break;
			case 12:
	            put('c');
	            break;
			case 13:
	            put('d');
	            break;
			case 14:
	            put('e');
	            break;
			case 15:
	            put('f');
	            break;
		
		}*/
	} 
}

O_Stream& O_Stream::operator<< (char* text){
		int i = 0;
		while(text[i] != '\0'){
			put(text[i]);
			i++;	
		}
	return *this;
}

O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)){
	return fkt(*this);
}





O_Stream& endl (O_Stream& os){
os.put('\n');
return os;
}
// BIN: waehlt das binaere Zahlensystem aus.

O_Stream& bin (O_Stream& os){
	os.base=2;
return os;
}
       
// OCT: waehlt das oktale Zahlensystem aus.

O_Stream& oct (O_Stream& os){
	os.base = 8;
return os;
}
        
// DEC: waehlt das dezimale Zahlensystem aus.

O_Stream& dec (O_Stream& os){
	os.base = 10;
return os;
}
// HEX: waehlt das hexadezimale Zahlensystem aus.

O_Stream& hex (O_Stream& os){
	os.base = 16;
return os;
}


