CC 		= gcc
CFLAGS	=	-Wall -Wextra -Werror -g
NAME	=	cub3d
DEBUG	=	-fsanitize=address
LIBFT	=	./libs/libft/
SRCS	=	./srcs/main.c
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

ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

ifeq ($(OS), Darwin)
LIBS	= -framework OpenGL -framework AppKit
MLX	= ./libs/mlx/
else
LIBS	= -lXext -lX11 -lm -lz
MLX	= ./libs/mlx_linux/
endif

all: $(SUBM_FLAG) mlx libft cub3d

submodule:
	@git submodule init 
	@git submodule update

%.o : %.c
	@echo "$(B_BLUE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

banner:
	@echo "\n${PURPLE}======== Cub3d ========$(NC)"

libft:
	@echo "\n${BLUE}======== Libft ========${NC}"
	@$(MAKE) -C $(LIBFT)

mlx:
	@echo "\n${BLUE}======== MLX ========${NC}"
	@$(MAKE) -C $(MLX)

$(NAME): banner $(OBJS)
	@$(CC) $(FLAGS_OS) $(CFLAGS) $(OBJS) $(MLX)libmlx.a $(LIBFT)libft.a $(READLINE) $(FSAN) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX) clean
	@echo "${B_RED}🧹 Cleaning: ${RED} object files $(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re banner $(NAME) libft mlx submodule
