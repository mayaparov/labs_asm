#include <stdio.h>
#include <cmath>
#include <locale.h>
#include "stdafx.h"


using namespace std;
bool check_params(char x1, char x2, char x3)
{
	if ((x1 <= '9') && (x1 >= '0') && (x2 <= '9') && (x2 >= '0') && (x3 <= '9') && (x3 >= '0'))
		return 1;
	else return 0;
}

void laba(char x1, char x2, char x3)
{
	if (check_params(x1, x2, x3)) printf("Lab 3 parameters: x1='%c', x2='%c', x3='%c'\n", x1, x2, x3);
	else 
	{
		printf("Invalid input\n");
		return;
	}
	__asm
	{
		{
			mov al, x1;
			mov cl, x3;
			cmp al, cl; //сравниваем х1 и х3
			jne ELSE; //если х1 != x3, то переходим на метку ELSE
			mov bl, x2; 
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
	printf("Result:  %c%c%c", x1, x2, x3);
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