#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h> 

int my_putChar(char c) {
  return write(1, &c, 1);
}

int my_strLen(char* param_1){
    
     int i = 0;
     while(param_1[i] != '\0'){
         i++;

     }
     return i;
}

void my_putStr(char* param_1){
  
  if(param_1 == NULL){
    my_putStr("(null)");
  }

     int i = 0;
     while(*(param_1+i)!='\0'){
         my_putChar(*(param_1 + i));
         i++;
     };
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        char temp;
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        
        start++;
        end--;
    }
}

char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; 
 
    reverse(str, i);
 
    return str;
}

 int convert(long nbr, int base) 
{ 
	char representation[]= "0123456789abcdefg"; 
	char buffer[50];
	char* ptr; 

	ptr = &buffer[49];  
    *ptr = '\0';        
	
	while(nbr != 0)
	{ 
		*--ptr = representation[nbr % base]; 
		nbr /= base;                         
	}
    my_putStr(ptr); 
    
    return my_strLen(ptr);                 
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

int main(){

    return 0;
}