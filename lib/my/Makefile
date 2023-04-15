##
## EPITECH PROJECT, 2023
## B-PSU-200-MPL-2-1-42sh-kylian.labrador
## File description:
## Makefile
##

CPPFLAGS = -I./

SRC_DISP = disp/my_print_3darray.c \
		   disp/my_print_array.c \
		   disp/my_putchar.c \
		   disp/my_putnbr.c \
		   disp/my_putstr.c \

SRC_LEN = len/my_2darray_len.c\
		  len/my_3darray_len.c\
		  len/my_strlen.c\

SRC_MALLOC = malloc/malloc_2d_char.c\

SRC = $(SRC_DISP)\
	  $(SRC_LEN)\
	  $(SRC_MALLOC)\
	  my_revstr.c\
	  my_strcat.c\
	  my_strcomp.c\
	  my_strcpy.c\
	  my_strncomp.c\

OBJ = $(SRC:.c=.o)
TARGET = libmy.a

$(TARGET): $(OBJ)
	$(AR) rc $@ $^

all: $(TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
