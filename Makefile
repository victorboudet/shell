##
## EPITECH PROJECT, 2023
## .utils
## File description:
## Makefile
##

FUNC = functions
UTILS = utils
HANDLER = handlers

CFLAGS = -W -Wall -Wextra -Werror
CPPFLAGS = -I./include

SRC_FUNC = $(FUNC)/my_env.c \
		   $(FUNC)/my_exit.c \
		   $(FUNC)/my_cd.c \
		   $(FUNC)/my_exec.c \
		   $(FUNC)/my_setenv.c \
		   $(FUNC)/my_unsetenv.c \

SRC_HANDLER = $(HANDLER)/sigint.c \
			  $(HANDLER)/sigbase.c \
			  $(HANDLER)/sigsegv.c \

SRC_UTILS = $(UTILS)/my_puts.c \
			$(UTILS)/my_str_comp.c \
			$(UTILS)/my_len.c \
			$(UTILS)/get_arg.c \
			$(UTILS)/my_strcat.c \
			$(UTILS)/my_putnbr.c \
			$(UTILS)/str_get.c \
			init_env.c \
			$(UTILS)/my_revstr.c \
			$(UTILS)/new_arg.c \

SRC = main.c \
	  pipe.c \
	  $(SRC_FUNC) \
	  $(SRC_UTILS) \
	  $(SRC_HANDLER) \

OBJ = $(SRC:.c=.o)
TARGET = 42sh

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(CPPFLAGS)

all: $(TARGET)
	make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
