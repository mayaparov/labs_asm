#include <stdio.h>
#include <cmath>
#include <locale.h>
#include "stdafx.h"


void laba(char x1, char x2, char x3)
{
	__asm
	{
		{
			jmp CODE;
		INVALID:
			mov x1, 'e';
			mov x2, 'r';
			mov x3, 'r';
			jmp EXIT;
		CODE:
			mov al, x1;
			cmp al, '9';
			jg INVALID;
			cmp al, '0';
			jl INVALID;
			
			mov cl, x3;
			cmp cl, '9';
			jg INVALID;
			cmp cl, '0';
			jl INVALID;
			
			cmp al, cl; //сравниваем х1 и х3
			jne ELSE; //если х1 != x3, то переходим на метку ELSE
			
			mov bl, x2;
			cmp bl, '9';
			jg INVALID;
			cmp bl, '0';
			jl INVALID;
			
			cmp al, bl; //сравниваем х1 и х2
			je EXIT;//если х1 == x3 == x2, то переходим на метку ELSE
			//следующий блок будет выполняться, если x1==x3!=x2
			cmp bl, '7';
			jge EXIT; //если число больше или равно 7, то переходим на метку EXIT
			add bl, 3;
			mov x2, bl;
		ELSE:
			mov x3, al;
			mov x1, cl;
		EXIT: NOP; //совершаем перенос, если изменения строки закончены
		
		}
	}
	if (x1 == 'e' && x2 == 'r' && x3 == 'r') 
	{
		printf("Invalid input\n");
		return;
	}
	else printf("Result:  %c%c%c", x1, x2, x3);
	printf("\n");
}


int main()
{
	//setlocale(LC_ALL, "rus");
	char str[3];
	printf("\ninput values x1, x2, x3\n");
	scanf_s("%c", &str[0]);
	scanf_s("%c", &str[1]);
	scanf_s("%c", &str[2]);
	
	laba(str[0], str[1], str[2]);
	return 0;
}