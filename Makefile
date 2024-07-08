NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILBXDIR = minilibx-linux
MINILBX = $(MINILBXDIR)/libmlx_Linux.a -lXext -lX11 -lm -g
SRC = init_mlx.c \
      main.c \
      draw.c \
      utils.c \
      fractol.c \

OBJ = $(SRC:.c=.o)
GIT_CLONE = git clone
MINILIB_URL = https://github.com/42Paris/minilibx-linux.git

all: $(NAME)

minilibx:
	$(GIT_CLONE) $(MINILIB_URL)
	cd $(MINILBXDIR) && ./configure && make
	@echo "\033[1;32mMinilibx compiled successfully!\033[0m"

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILBXDIR)/libmlx_Linux.a
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MINILBX)
	@echo "\033[1;34m./$(NAME) generated successfully!\033[0m"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
