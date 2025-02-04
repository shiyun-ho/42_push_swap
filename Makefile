# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 20:03:42 by hshi-yun          #+#    #+#              #
#    Updated: 2025/02/02 16:09:36 by hshi-yun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

PROGRAM = push_swap
CLIENT = client

SRC = push_swap.c arg_check_utils.c stack_utils.c sort_stack.c swap_operations.c \
	  rotate_operations.c reverse_rotate_operations.c push_operations.c \
	  quick_sort.c radix_sort.c \

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