#include <stdio.h>

int hexToDec(char hex){
	int dec;
	switch(hex){
		case '0':
			dec = 0;
			break;
		case '1':
			dec = 1;
			break;
		case '2':
			dec = 2;
			break;
		case '3':
			dec = 3;
			break;
		case '4':
			dec = 4;
			break;
		case '5':
			dec = 5;
			break;
		case '6':
			dec = 6;
			break;
		case '7':
			dec = 7;
			break;
		case '8':
			dec = 8;
			break;
		case '9':
			dec = 9;
			break;
		case 'a':
			dec = 10;
			break;
		case 'b':
			dec = 11;
			break;
		case 'c':
			dec = 12;
			break;
		case 'd':
			dec = 13;
			break;
		case 'e':
			dec = 14;
			break;
		case 'f':
			dec = 15;
			break;
		default:
			dec = -1;
			break;
	}
	return dec;
}

char decToHex(int dec){
	char hex;
	switch(dec){
		case 0:
			hex = '0';
			break;
		case 1:
			hex = '1';
			break;
		case 2:
			hex = '2';
			break;
		case 3:
			hex = '3';
			break;
		case 4:
			hex = '4';
			break;
		case 5:
			hex = '5';
			break;
		case 6:
			hex = '6';
			break;
		case 7:
			hex = '7';
			break;
		case 8:
			hex = '8';
			break;
		case 9:
			hex = '9';
			break;
		case 10:
			hex = 'a';
			break;
		case 11:
			hex = 'b';
			break;
		case 12:
			hex = 'c';
			break;
		case 13:
			hex = 'd';
			break;
		case 14:
			hex = 'e';
			break;
		case 15:
			hex = 'f';
			break;
		default:
			hex = '-';
			break;
	}
	return hex;
}

bool even(int x) {
	if (x%2 == 0) {
		return true;
	}
	return false;
}

bool prime(int x) {
	int divisores = 0;
	for (int i=2; i<x; i++){
		if (x%i == 0) {
			divisores++;
		}
	}
	if (divisores == 0){
		return true;
	}
	return false;
}

