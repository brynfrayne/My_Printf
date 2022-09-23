int main()
{   
    char character = '9';
    char* char_ptr = &character;
    
    printf("case pointer-> ");
    int res_printf = printf("%p", char_ptr);
    printf("\nres_printf:%d\n\n",res_printf);
    printf("case pointer-> ");
    int res_my_printf = my_printf("%p", char_ptr);
    // printf("\n");
    printf("res_my_printf:%d\n\n",res_my_printf);
    // int// 
    
    // int zero = 0; 
    // t a = 123; -- worked
    //  int neg = -123; -- worked
    // int* p = &a;
    // char b = 'l';
    // char* c = "I love baby Yoda! ! !";
    // char** ptr = &c;
    char* nil_str;
    nil_str = NULL;

    // //TEST TO COMPARE RETURN VALUES
    if (res_my_printf == res_printf)
    {
        printf("OK -> Same return value as the real printf\n");
    }
    else
    {
        printf("KO -> Not same return value as the real printf\n");
    }
    //TEST CASES
    my_printf("\nMy_printf:\n");
    // my_printf("case 'zero' -> %d\n", zero); -- worked
    // printf("res_my_printf:%d\n", res_my_printf);
    // my_printf("case 'd' -> %d\n", a); -- worked
    // my_printf("case 'd' negative -> ");
    // res_my_printf = my_printf("%d", neg); -- worked
    // printf("\nres_my_printf:%d\n", res_my_printf);
    //  my_printf("case 'o' -> %o!\n", a); -- worked
    // my_printf("case 'u' -> %u\n", a); -- Worked
    // my_printf("case 'x' -> %x\n", a); -- Worked
    // my_printf("case 'c' -> %c\n", b); -- worked
    // my_printf("case 's' -> %s\n", c); -- worked
    // my_printf("case int* 'p' -> %p\n", p); -- worked
    //  my_printf("case char* 'p' -> %p\n", ptr); -- worked
    // res_my_printf = my_printf("multiple args -> %d - %d - %d!\n", 2048, 0, -1337); -- worked
    // printf("res_my_printf:%d\n", res_my_printf);
    // my_printf("testing out invalid %z\n"); // does not print out the %
    // res_my_printf = my_printf("NULL STRING -> %s!", nil_str); -- worked
    // printf("\nres_my_printf:%d\n", res_my_printf);
    my_printf("\nThe REAL printf:\n");
    // printf("case 'zero' -> %d\n", zero); -- worked
    // printf("res_printf:%d\n\n", res_printf);
    // printf("case 'd' -> %d\n", a); -- worked
    // printf("case 'd' negative -> ");
    // res_printf = printf("%d", neg); -- worked
    // printf("\nres_printf:%d\n\n", res_printf);
    // printf("case 'o' -> %o!\n", a); -- worked
    // printf("case 'u' -> %u\n", a); -- Worked
    // printf("case 'x' -> %x\n", a); -- Worked
    // printf("case 'c' -> %c\n", b); -- worked
    // printf("case 's' -> %s\n", c); -- worked
    // res_printf = printf("NULL STRING -> %s!", nil_str); -- worked
    // printf("\nres_printf:%d\n", res_printf);
    // printf("case int* 'p' -> %p\n", p); -- worked
    // printf("case char* 'p' -> %p\n", ptr); -- worked
    // res_printf = printf("multiple args -> %d - %d - %d!\n", 2048, 0, -1337); -- worked
    // printf("res_printf:%d\n", res_printf);
    // printf("testing out invalid %z\n"); // returns an error  message for invalid conversion specifier 

    if (res_my_printf == res_printf)
        {
            printf("OK -> Same return value as the real printf\n");
        }
        else
        {
            printf("KO -> Not same return value as the real printf\n");
        }

}