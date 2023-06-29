#include <stdio.h>


int main()
{
    char A[16] = { 3, 1, 4, 8, 100, 'a', '\n', -1, 10, -2, -3, -5, -120, 45, 2, 3 }, B[16];
    short int* C[16];
    
    char count, sum;
    
    __asm
{
    xor BL, BL; очистка регистра BL
    mov sum, BL; сумма абс.значений
    mov count, BL; счетчик подходящих элементов
    xor EBX, EBX; EBX = 0 – индекс элементов массивов
BEG: mov AL, [A + EBX];
    cmp AL, -2;
    jl END;
    cmp AL, 3;  
    jg END;
    mov[B + EBX*TYPE B], AL; код, который начинает выполняться, если число в диапазоне
    lea ECX, A[EBX*TYPE A];
    sub ECX, EBX;
    mov C[EBX*TYPE C], ECX;
    mov BL, count;
    inc BL;
    mov count, BL; Увеличили счётчик
    cmp AL, 0;
    jge HIG;
    neg AL; Меняем знак, если число из массива отрицательное
    jmp HIG;
HIG:mov BL, sum;
    add BL, AL; складываем элемент массива и sum
    mov sum, BL;
jmp END;
END: inc EBX;
cmp EBX, 10h;
jl BEG;
NOP;
}

    printf("sum = %d\n", sum);
    printf("count = %d\n", count);
    for (int i = 0; i < 16; i++)
        printf("%d: A = %d\tB = %d\t\tC = %p\n", i, A[i], B[i], C[i]);
    return 0;
}