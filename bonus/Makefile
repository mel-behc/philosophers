CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread 
BONUS = philo_b
HEADER_B = ./bonus/philo.h
SRC_B = main.c \
			argsChecker.c \
			functions1.c \
			functions2.c \
			routines.c
OBJ_B = $(SRC_B:.c=.o)

all: $(BONUS)

$(BONUS): $(OBJ_B)
	@$(CC) $(OBJ_B) -o $(BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_B)

clean:
	@rm -rf $(OBJ_B)

fclean: clean
	@rm -rf $(BONUS)

re: fclean all