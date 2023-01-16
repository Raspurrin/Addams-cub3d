# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 21:37:57 by mialbert          #+#    #+#              #
#    Updated: 2022/10/14 04:53:08 by mialbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = $(shell find . -iname "*_bonus.c")
OBJS = $(SRCS:.c=.o)

NC		:= \033[0m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m

all : $(OBJS)

%.o : %.c
	@echo "${PURPLE}======== GNL ========${NC}"
	@echo "$(B_BLUE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

$(OBJS) : 
	@$(CC) -std=c11 $(CFLAGS) -ggdb3 -c $(SRCS) 

bonus :
	@$(CC) -std=c11 $(CFLAGS) -ggdb3 $(BONUS_SRCS)

unittest:
	cd gnlTester && make && cd ..

valgrind: test
	@echo ""
	@valgrind --leak-check=full ./a.out

clean:
	@echo "${B_RED}🧹 Cleaning: ${RED} $(notdir $(OBJS))"
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re : clean all

.PHONY: clean fclean re test valgrind all bonus unittest
