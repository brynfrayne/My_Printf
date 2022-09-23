my_printf: bryn_my_printf.o  bryn_my_functions.o 
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -o bryn_my_printf bryn_my_printf.o  bryn_my_functions.o 

bryn_my_functions.o: bryn_my_functions.c bryn_my_printf.h 
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -O -c bryn_my_functions.c

bryn_my_printf.o: bryn_my_printf.c bryn_my_printf.h
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -O -c bryn_my_printf.c

clean:
	rm -f *.o

fclean: clean
	rm -f bryn_my_printf

re: fclean all