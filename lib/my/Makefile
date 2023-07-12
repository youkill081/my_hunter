##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC	=	functions.c \
		my_compute_square_root.c \
		my_revstr.c \
		my_strcapitalize.c \
		my_strcpy.c \
		my_str_islower.c \
		my_strlowcase.c \
		my_strncpy.c \
		my_strupcase.c \
		functions_2.c \
		my_find_prime_sup.c \
		my_is_prime.c \
		my_show_word_array.c \
		my_strcat.c \
		my_strdup.c \
		my_str_isnum.c \
		my_strncat.c \
		my_strstr.c \
		functions_3.c \
		my_compute_factorial_rec.c \
		my_getnbr.c \
		my_put_nbr.c \
		my_sort_int_array.c \
		my_strcmp.c \
		my_str_isalpha.c \
		my_str_isupper.c \
		my_strncmp.c \
		my_str_to_word_array.c \
		is_digits.c \
		is_int.c \
		is_length.c \
		my_str_to_int.c \
		append.c \
                calc.c \
                conversion.c \
                string.c \
		index.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

clean:	move
	rm $(OBJ)

move:	 createlib
	cp libmy.a ../
	cp my.h ../../include
	cp strings.h ../../include

createlib :	createc
	ar rc $(NAME) $(OBJ)

createc:	*.c
	gcc $(SRC) -c -I string.h
	ar rc $(NAME) $(OBJ)
