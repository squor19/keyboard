#include <klawiatura.h>
#include <avr/io.h>
#include <util/delay.h>

int getValueFromKeyboard() {
	unsigned char wiersz, kolumna, key;
	for(kolumna=0xEF, key = 1; kolumna >= 0x71; (kolumna <<= 1 | 0x01)&0xFF) {
		SP_PORT = kolumna;
		for(wiersz=0x01; wiersz <= 0x08; wiersz <<= 1, key++) {
			if(!(SP_PIN & wiersz))
			return convert(SP_PIN);
		}
	}
	return 0;
}


int convert(int code) {
	switch(code) {
		case 0b11101110: // 1 wiersz, 1 kolumna
		return 0b01;  //zwraca 1
		break;
		case 0b11011110: // 1 wiersz, 2 kolumna
		return 0b10;  //zwraca 2
		break;
		case 0b10111110: // 1 wiersz, 3 kolumna
		return 0b11;  //zwraca 3
		break;
		case 0b01111110: // ...
		return 0b100; //zwraca 4
		break;
		case 0b11101101: //  wiersz, 1 kolumna
		return 0b101; //zwraca 5
		break;
		case 0b11011101:
		return 0b110; //zwraca 6
		break;
		case 0b10111101:
		return 0b111; //zwraca 7
		break;
		case 0b01111101:
		return 0b1000;//8
		break;
		case 0b11101011:
		return 0b1001;//9
		break;
		case 0b11011011:
		return 0b1010;//10
		break;
		case 0b10111011:
		return 0b1011;//11
		break;
		case 0b01111011:
		return 0b1100;//12
		break;
		case 0b11100111:
		return 0b1101;//13
		break;
		case 0b11010111:
		return 0b1110;//14
		break;
		case 0b10110111:
		return 0b1111; //15
		break;
		case 0b01110111:
		return 0b10000; //16
		break;
		default:
		break;
	}
	return 0x00;
}
