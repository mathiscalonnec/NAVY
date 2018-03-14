DIR	=	src/

INC_DIR =	include/

LIB_DIR =	lib/

SRC	=	$(DIR)main.c			\
		$(DIR)check_file_validity.c	\
		$(DIR)connection.c		\
		$(DIR)map_datas_manipulations.c	\
		$(DIR)parse_file.c		\
		$(DIR)print_help.c		\
		$(DIR)init_player.c		\
		$(DIR)read_coordinates.c	\
		$(DIR)transfer_value.c		\
		$(DIR)game.c			\
		$(DIR)modify_array.c		\
		$(DIR)end_game.c

CFLAGS	=	-Wall -Wextra -Wpedantic -I ./$(INC_DIR) -I ./$(LIB_DIR)$(INC_DIR) -fdiagnostics-color

LFLAGS	=	-L $(LIB_DIR) -lmy

CC	=	gcc -g

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib && make && make clean && cd ..
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	cd lib && make fclean && cd ..
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
