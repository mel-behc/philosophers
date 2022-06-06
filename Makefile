CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread 
NAME = philo
HEADER = philo.h
SRC = main.c argsChecker.c functions1.c functions2.c  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all