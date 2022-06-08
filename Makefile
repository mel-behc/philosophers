CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread 

NAME = philo
BONUS = philo_b

HEADER = ./mandatory/philo.h
HEADER_B = ./bonus/philo.h

SRC = ./mandatory/main.c \
		./mandatory/argsChecker.c \
		./mandatory/functions1.c \
		./mandatory/functions2.c  

SRC_B = ./bonus/main.c \
		./bonus/argsChecker.c \
		./bonus/functions1.c \
		./bonus/functions2.c \
		./bonus/routines.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME) $(BONUS)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ_B)
	@$(CC) $(OBJ_B) -o $(BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_B)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re: fclean all