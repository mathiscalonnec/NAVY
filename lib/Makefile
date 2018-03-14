##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile
##

INC_DIR =	include/

DIR	=	src/

SRC	=	$(DIR)my_putchar.c	\
		$(DIR)my_put_nbr.c	\
		$(DIR)my_putstr.c	\
		$(DIR)my_strlen.c	\
		$(DIR)my_getnbr.c	\
		$(DIR)my_strcpy.c

CFLAGS	=	-Wall -I $(INC_DIR)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $NAME

$NAME:		$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
