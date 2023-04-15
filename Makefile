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
CPPFLAGS = -I./include -L./lib/my -lmy

SRC_FUNC = $(FUNC)/my_env.c \
		   $(FUNC)/my_exit.c \
		   $(FUNC)/my_cd.c \
		   $(FUNC)/my_exec.c \
		   $(FUNC)/my_setenv.c \
		   $(FUNC)/my_unsetenv.c \

SRC_HANDLER = $(HANDLER)/sigint.c \
			  $(HANDLER)/sigbase.c \
			  $(HANDLER)/sigsegv.c \

SRC_UTILS = $(UTILS)/my_len.c \
			$(UTILS)/get_arg.c \
			$(UTILS)/str_get.c \
			init_env.c \
			$(UTILS)/new_arg.c \

SRC = main.c \
	  redirect.c \
	  format_arg.c \
	  execute.c \
	  $(SRC_FUNC) \
	  $(SRC_UTILS) \
	  $(SRC_HANDLER) \

OBJ = $(SRC:.c=.o)
TARGET = 42sh

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C lib/my
	$(CC) $^ -L./lib/my -lmy -o $@ $(CPPFLAGS)

clean:
	make clean -C lib/my
	$(RM) $(OBJ)

fclean: clean
	make fclean -C lib/my
	$(RM) $(TARGET)

re: fclean all
