##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC    =	main.c	\
			separate_str.c	\
			compute.c	\
			calculate.c	\

OBJ    =    $(SRC:.c=.o)

NAME	=	107transfer

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm
		

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

git:
	echo -e "*.a\n*.o\n#*#\n*~\n#*" > .gitignore
	echo $(NAME) >> .gitignore
