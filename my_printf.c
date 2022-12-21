#include "my_printf.h"

int main()
{
    char character = '9';
    char* char_ptr = &character;
    // printf("char_ptr: %s\n", char_ptr);
    int res_my_printf = my_printf("case pointer-> %p\n", char_ptr);
    int res_printf = printf("case pointer-> %p\n", char_ptr);
    int zero = 0;
    int a = 123;
    int neg = -123;
    int* p = &a;
    char b = 'l';
    char* c = "I love baby Yoda! ! !";
    char** ptr = &c;
    char* nil_str = NULL;

    //TEST TO COMPARE RETURN VALUES
    if (res_my_printf == res_printf)
    {
        printf("OK -> Same return value as the real printf\n");
    }
    else
    {
        printf("KO -> Not same return value as the real printf\n");
    }
    //TEST CASES
    my_printf("My_printf:\n");
    my_printf("case 'zero' -> %d\n", zero);
    my_printf("case 'd' -> %d\n", a);
    my_printf("case 'd' negative -> %d\n", neg);
    my_printf("case 'o' -> %o!\n", a);
    my_printf("case 'u' -> %u\n", a);
    my_printf("case 'x' -> %x\n", a);
    my_printf("case 'c' -> %c\n", b);
    my_printf("case 's' -> %s\n", c);
    my_printf("case int* 'p' -> %p\n", p);
    my_printf("case char* 'p' -> %p\n", ptr);
    my_printf("multiple args -> %d - %d - %d!\n", 2048, 0, -1337);
    my_printf("NULL STRING -> %s!\n", nil_str);
    my_printf("The REAL printf:\n");
    printf("case 'zero' -> %d\n", zero);
    printf("case 'd' -> %d\n", a);
    printf("case 'd' negative -> %d\n", neg);
    printf("case 'o' -> %o!\n", a);
    printf("case 'u' -> %u\n", a);
    printf("case 'x' -> %x\n", a);
    printf("case 'c' -> %c\n", b);
    printf("case 's' -> %s\n", c);
    printf("NULL STRING -> %s!\n", nil_str);
    printf("case int* 'p' -> %p\n", p);
    printf("case char* 'p' -> %p\n", ptr);
    printf("multiple args -> %d - %d - %d!\n", 2048, 0, -1337);
}


// printf will return the length of the final string

int my_printf(char * restrict format, ...){

    va_list args;
    va_start(args, format);

    int length = 0;
    char* strVal;
    char charVal;
    int intVal;
    long ptrVal;
    char str[100];

    for(int i = 0; format[i] != '\0'; i++){

        if(format[i] != '%'){
            my_putChar(format[i]);
            length++;
        }

        if(format[i] == '%'){
            i++;

            switch(format[i]){

                case 'd':

                    intVal = va_arg(args, int);

                    if(intVal == 0){
                        my_putChar('0');
                        length++;
                        break;

                    } else {
                        strVal = my_itoa(intVal, str, 10);
                        my_putStr(strVal);
                        length += my_strLen(strVal);
                        break;
                    }

                case 'o':

                    intVal = va_arg(args, int);
                    strVal = my_itoa(intVal, str, 8);
                    my_putStr(strVal);
                    length += my_strLen(strVal);
                    break;

                case 'u':

                    intVal = va_arg(args, int);
                    strVal = my_itoa(intVal, str, 10);
                    my_putStr(strVal);
                    length += my_strLen(strVal);
                    break;

                case 'x':

                    intVal = va_arg(args, int);
                    strVal = my_itoa(intVal, str, 16);
                    my_putStr(strVal);
                    length += my_strLen(strVal);
                    break;

                case 's':

                    strVal = va_arg(args, char*);

                    if(strVal == NULL){
                        my_putStr("(null)");
                        length += 6;
                        break;

                    } else {
                        my_putStr(strVal);
                        length += my_strLen(strVal);
                        break;
                    }

                case 'c':

                    charVal = va_arg(args, int);
                    my_putChar(charVal);
                    length ++;
                    break;

                case 'p':

                    ptrVal = va_arg(args, long);
                    my_putStr("0x");
                    length += my_strLen("0x");
                    length += convert(ptrVal, 16);
                    break;

                default:
                    my_putChar(format[i]);
                    length++;
                    break;

            }
        }
    }
    va_end(args);
    return length;
}
