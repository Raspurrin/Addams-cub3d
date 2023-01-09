CC 		= gcc
CFLAGS	=	-Wall -Wextra -Werror -g
NAME	=	cub3d
DEBUG	=	-fsanitize=address
LIBFT	=	./libs/libft/
SRCS	=	./srcs/main.c

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

all: $(SUBM_FLAG) libft cub3d

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

$(NAME): banner $(OBJS)
	@$(CC) $(FLAGS_OS) $(CFLAGS) $(ADDUSER) $(OBJS) $(LIBFT)libft.a $(READLINE) $(FSAN) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "$(PINK)✨Minishell successfully cleaned!✨$(RESET)"

fclean: clean
	@rm -f philo

re: fclean all
	cd includes

.PHONY: all clean fclean re banner $(NAME) libft e submodule
