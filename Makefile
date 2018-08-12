# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/04 17:12:22 by zmiantud          #+#    #+#              #
#    Updated: 2018/08/12 11:11:31 by zmiantud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRCS :=	main.c
SRCS += get_tables.c
SRCS += heuristics.c
SRCS += piece_fit_test.c
SRCS += submit_coord.c
SRCS += trim_piece.c
SRCS += arraydel.c
SRCS += set_next_strategy.c
SRCS += get_new_piece_coord.c

CC = gcc

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[34mCreating $(NAME) ...\033[0m"
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "\033[32m$(NAME) created succesfully\033[0m"

clean:
	@echo "\033[33mRemoving .o files of $(NAME) ...\033[0m"
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[31m.o files removed\033[0m"

fclean: clean
	@echo "\033[33mRemoving $(NAME) ...\033[0m"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) removed successfully\033[0m"

re: fclean all
