#include "my_printf.h"

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
     while(param_1[i] != '\0'){
         my_putChar(param_1[i]);
         i++;
     };
}

char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}


/* A utility function to reverse a string  */
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
        // swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

// I deleted this function in my handed in copy
void swap(int* param_1, int* param_2)
 {
     char temp;
     temp = *param_1;
     *param_1 = *param_2;
     *param_2 = temp;

 }

 int convert(long nbr, int base) //makes the conversion to unsigned - cases o, u, x
{
	char hexNumSet[]= "0123456789abcdefg"; //ASCII needed for the max conversion (hexadecimal)
	char buffer[50];
	char* ptr;

	ptr = &buffer[49];  //pointing for the end, it will make the "reverse" function
    *ptr = '\0';        //null char in the end

	while(nbr != 0)
	{
		*--ptr = hexNumSet[nbr % base]; //feeds the buffer with the chars converted; decrementing because we started from the end
		nbr /= base;                         // nbr%base && nbr/= base - same putnbr logic
	}
    my_putStr(ptr);
    printf("\nptr: %s\nmy_strLen(ptr):%d\n", ptr, my_strLen(ptr));
    return my_strLen(ptr);                  //I'm returning the length of ptr to know how many characters are being printed
}
