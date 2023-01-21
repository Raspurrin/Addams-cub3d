CC 		= gcc
CFLAGS	=	-Wall -Wextra -Werror -g
NAME	=	cub3d
DEBUG	=	-fsanitize=address
LIBFT	=	./libs/libft/
SRCS	=	./srcs/main.c \
			./srcs/errno.c \
			./srcs/free.c \
			./srcs/init.c \
			./srcs/graphics/colour.c \
			./srcs/graphics/textures.c \
			./srcs/parsing/legenda_check.c \
			./srcs/parsing/error_check.c \
			./srcs/parsing/read_map.c \
			./srcs/parsing/validate_map.c \
			./srcs/parsing/validate_map_utils.c \
			./srcs/parsing/is_char_checks.c \
			./srcs/engine/mlx.c \
			./srcs/engine/draw.c \
			./srcs/engine/vectors.c \
			./srcs/keyhooks.c

OS		=	$(shell uname -s)

OBJS	= $(SRCS:.c=.o)

NC		:= \033[0m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
PURPLE	:= \033[0;35m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m

SUBM_STATE := $(shell find libs/libft -type f)

ifeq ($(DEBUG),1)
FSAN 	=	-fsanitize=address
else 
FSAN 	=
endif

ifeq ($(OS), Darwin)
LIBS	= -framework OpenGL -framework AppKit
MLXDIR	=	./libs/mlx/
MLXLIB	= libmlx.a
else
LIBS	= -lXext -lX11 -lm -lz
MLXDIR	=	./libs/minilibx-linux/
MLXLIB	= libmlx_Linux.a
endif

MLX_COMPILE_STATE = $(shell find $(MLXDIR)$(MLXLIB))

ifeq ($(MLX_COMPILE_STATE),$(MLX_COMPILE_STATE))
MLX_COMPILE_FLAG = mlx
else
MLX_COMPILE_FLAG =
endif

all: mlx libft cub3d

submodule:
	@git submodule init 
	@git submodule update

%.o : %.c
# @echo "$(B_BLUE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;35m•\033[0;35m\c"

banner:
# @echo "\n${PURPLE}======== Cub3d ========$(NC)"

libft:
# @echo "\n${BLUE}======== Libft ========${NC}"
	@$(MAKE) -C $(LIBFT)

mlx:
# @echo "\n${BLUE}======== MLX ========${NC}"
	@$(MAKE) -C $(MLXDIR)

$(NAME): banner $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a $(MLXDIR)$(MLXLIB) $(FSAN) $(LIBS) -o $(NAME)

git:
	git add .
	@read -p "Enter the commit message: " halp; \
	git commit -m "$$halp"
	git push
	@echo "$(BLUE)All added, commited and pushed✨$(RESET)"

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLXDIR) clean
	@echo "${B_RED}🧹 Cleaning: ${RED} object files $(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33m•\033[0;33m\c"
	@echo "${B_RED}🧹 Cleaning: ${RED} $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re banner $(NAME) libft mlx submodule
