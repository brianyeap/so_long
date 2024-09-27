Library = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

Compiler = gcc -g
Flags = -Wall -Wextra -Werror

MLX_DIR = ./MLX
MLX_LIB = $(MLX_DIR)/libmlx.a

MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


OUTN = $(Library)
NAME = $(OUTN)

INCLUDES = -I./ -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT) $(MLX_LIB)
	$(Compiler) $(Flags) -o $(OUTN) $(OFILES) $(LIBFT) $(MLXFLAGS)

%.o: %.c
	$(Compiler) $(Flags) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
