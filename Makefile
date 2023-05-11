##
## EPITECH PROJECT, 2023
## .utils
## File description:
## Makefile
##

FUNC = functions
UTILS = utils
HANDLER = handlers
STAR = star

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
			$(UTILS)/my_strstr.c\
			init_env.c \
			$(UTILS)/my_revstr.c \
			$(UTILS)/new_arg.c \
			$(UTILS)/linked_list_to_array.c \

SRC_STAR =  $(STAR)/clean_str.c\
			$(STAR)/end_string.c\
			$(STAR)/star_bis.c\
			$(STAR)/star.c\
			$(STAR)/str_compare.c\
			$(STAR)/str_to_word_array.c\

SRC = main.c \
	  pipe.c \
	  $(SRC_FUNC) \
	  $(SRC_UTILS) \
	  $(SRC_HANDLER) \
	  $(SRC_STAR)\

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
