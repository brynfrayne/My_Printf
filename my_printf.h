#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdarg.h> //variable-length argument lists
#include <unistd.h> //write
#include <stdbool.h>
#include <stdio.h> //test printf

int my_putChar(char c);
int my_strLen(char* str);
void my_putStr(char* param_1);
char* my_itoa(int num, char* str, int base);
void reverse(char str[], int length);
void swap(int* param_1, int* param_2);
int my_putNum(int n);
int my_printf(char * restrict format, ...);
int convert(long nbr, int base);

#endif
