##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Fri Dec 18 12:07:14 2015 Pierre Bougon
##

SRC	=	./SRC/main_bsq.c \
		./SRC/print.c \
		./SRC/getinfos.c \
		./SRC/map.c \
		./SRC/brut_find.c

OBJS    =	$(SRC:.c=.o)

LIBPATH =	./lib/my

NAME    =	bsq

CC      =	gcc $(CFLAGS)

CFLAGS  =	-W -Wextra -Wall -Werror -ansi -pedantic

LDFLAGS =	-lmy -L$(LIBPATH) \
		-lprintf -L$(LIBPATH)

RM      =	rm -f

$(NAME): 	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

bonus:		all

clean:
		@$(RM) $(OBJS)

fclean: 	clean
		@$(RM) $(NAME)

re: 		fclean all
