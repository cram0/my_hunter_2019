##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME    =       my_hunter

SRC     =       my_hunter.c \

OBJ     =       $(SRC:.c=.o)

##CFLAGS  +=      -Wall -Wextra

CFLAGS  +=      -I./include

all     :       $(NAME)

$(NAME) :       $(OBJ)
				gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-audio

clean   :
				rm -f $(OBJ)
				rm -rf *.o

fclean  :       clean
				rm -f $(NAME)

re      :       fclean all