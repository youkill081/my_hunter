##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC     =      	main.c \
		window/manadge_window.c \
		window/calcul_window.c \
		menu/menu_init.c \
		menu/draw.c \
		menu/play_button.c \
		menu/credit_button.c \
		event/event.c \
		cursor/calcule.c \
		cursor/cursor.c \
		src/error.c \
		src/colision.c \
		src/spritesheet.c \
		game/game_init.c \
		game/draw.c \
		game/tree.c \
		game/bullet.c \
		game/bullet_list.c \
		game/shoot.c \
		game/text.c \
		game/game.c \
		game/pause.c \
		reload/reload.c \
		reload/init.c \
		reload/init2.c \
		duck/init_duck.c \
		duck/create.c \
		duck/create2.c \
		duck/draw.c \
		duck/generating.c \
		duck/shoot.c \
		duck/reset.c

CSFML	=	-lcsfml-system \
		-lcsfml-graphics \
		-lcsfml-window \
		-lcsfml-audio

OBJ     =       $(SRC:.c=.o)

NAME    =  	my_hunter

all:    $(NAME)

.c.o:
	gcc -c $< -I include/ -L lib/my/ -lmy -o $@ $(CSFML)

$(NAME):        $(OBJ)
	cd lib/my && make && cd ../../
	gcc -o $(NAME) $(OBJ) -I include/ -L lib/my/ -lmy $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
