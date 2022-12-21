my_printf: my_printf.o  my_functions.o
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -o my_printf my_printf.o  my_functions.o

my_functions.o: my_functions.c my_printf.h
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -O -c my_functions.c

my_printf.o: my_printf.c my_printf.h
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address -O -c my_printf.c

clean:
	rm -f *.o

fclean: clean
	rm -f my_printf

re: fclean all
