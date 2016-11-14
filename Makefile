LIBPATH = libft

LIB = $(LIBPATH)/libft.a

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L libft -lft -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	  ray_cast.c \
	  put_pixel_to_img.c \
	  parse.c \
	  key.c \
	  moves.c \
	  views.c \
	  algo.c \
	  init.c \
	  texel.c \
	  textures.c \

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)

re: fclean all
