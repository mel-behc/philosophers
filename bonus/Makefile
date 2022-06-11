CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread 
NAME = philo_b
HEADER_B = philo.h
SRC_B = main.c \
			argsChecker.c \
			functions1.c \
			functions2.c \
			routines.c
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_B)
	@$(CC) $(OBJ_B) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_B)

clean:
	@rm -rf $(OBJ_B)

fclean: clean
	@rm -rf $(NAME)

re: fclean all