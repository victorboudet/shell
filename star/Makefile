##
## EPITECH PROJECT, 2023
## stumper
## File description:
## Makefile
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

TARGET = redirect

CFLAGS = -W -Wextra -Wall -g3

all: $(TARGET)
	make clean

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	make clean
	$(RM) $(TARGET)

re:
	make fclean
	make all
