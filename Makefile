# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 20:03:42 by hshi-yun          #+#    #+#              #
#    Updated: 2024/12/28 17:00:41 by shiyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

PROGRAM = push_swap
CLIENT = client

SRC = push_swap.c
OBJ = $(SRC:.c=.o)

all: $(PROGRAM)

$(PROGRAM): $(SRC) $(OBJ) $(LIBFT)
	@echo ">>>Compiling sublibrary: $(LIBFT): "
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo ">>> Starting compilation of program file(s): "
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRC) libft.a
	@echo ">>> Compilation completed. "

%.o : %.c
	@echo ">>> Compiling .c files to .o files"
	$(CC) $(CFLAGS) -c -o $@ $^

norminette:
	@echo ">>> Checking norminette for all files"
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	rm -rf $(OBJ) 
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -rf $(PROGRAM) $(LIBFT).a
	$(MAKE) -C $(LIBFT) clean

re: fclean all

test: $(NAME) test.c
	@echo ">>> Running test files"
	$(CC) $(CFLAGS) -o test test.c libftprintf.a
	@./test


.PHONY: all norminette clean fclean re bonus test