CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = push_swap
SOURCES = check_error.c checkLine.c engineAB.c engineNB.c ft_atoi.c ft_split.c instruction1.c instruction2.c instruction3.c linkedList.c linkedList2.c linkedList3.c only.c push_swap.c utils1.c utils2.c
OBJECTS = $(SOURCES: %.c=%.o)
INCLUDE = -I./

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) -o $(NAME)

clean :
	rm -f $(OBJECTS) $(NAME)
