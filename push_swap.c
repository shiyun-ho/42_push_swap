/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/01 11:56:44 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include "push_swap.h"
# include <limits.h>
# include <stdlib.h>

int		handle_error(int *array, t_list **node)
{
	ft_printf("Error\n");
	if (array)
		free(array);
	if (node)
		ft_lstclear(node, del_int);
	exit(EXIT_FAILURE);
}

int		has_duplicate(int *array, int size)
{
	int	i;

	i = 0;
	while(i < (size - 1))
	{
		if (array[i] == array[i+1])
			return (1);
		i++;
	}
	return (0);
}

int		validate_input(long num, char *arg, int *array, int index)
{
	if (num == 0 && (arg[0] != '0' || arg[1] != '\0'))
		return (0);
	if (has_duplicate(array, index))
		return (0);
	return (1);
}

int		create_linked_list(int argc, char *argv[], int **array, t_list **head)
{
	int		i;
	long	num;
	t_list	*new_node;

	*array = (int *)malloc((argc - 1) * sizeof(int));
	if (!*array)
		return (0);
	i = 1;
	*head = NULL;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		(*array)[i - 1] = (int)num;
		if (num < INT_MIN || num > INT_MAX)
			handle_error(*array, head);
		new_node = ft_lstnew((int)num);
		if (!new_node)
			handle_error(*array, head);
		ft_lstadd_front(head, new_node);
		if (!validate_input(num, argv[i], *array, i))
			handle_error(*array, head);
		i++;
	}
	return (1);
}

/**
 * @brief: Checks user arg for valid operator
 */
int		is_valid_operator(char c, int index)
{
	if ((c == '+' || c == '-') && index == 0)
		return (1);
	else
		return (0);
}

/**
 * @brief: Checks for errorenous user input
*/
int		check_valid_argument(char *arg)
{
	int		j;

	j = 0;
	while (arg[j])
	{
		if (ft_isdigit(arg[j]))
			exit(EXIT_SUCCESS);
		else if (is_valid_operator(arg[j], j))
			exit(EXIT_SUCCESS);
		else
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

/**
 * @brief: Takes an argument `stack a`, formatted as list of integers,
 *         Display list of instructions to sort `stack a` in ascending order
*/
int	main(int argc, char *argv[])
{
	int		*duplicate_check_array;
	t_list	*head;

	if (argc == 1)
		return (0);
	// TODO: Refactor this to another function
	int i = 1;
	while (argv[i])
	{
		check_valid_argument(argv[i]);
		i++;
	}
	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
	{
		handle_error(duplicate_check_array, &head);
		ft_printf(">>>Exiting function...\n");
		exit(EXIT_FAILURE);
	}

	ft_printf("\n");
	ft_printf(">>>Starting sorting of stack...\n");
	
	//TODO: Sort the stack with the nodes given
	sort_stack(&head);
	// TODO: Clear both stack_a and stack_b before exiting

	ft_printf(">>>Clearing linked list nodes ...\n");
	ft_lstclear(&head, del_int);
	ft_printf(">>>Ending push_swap() program...\n");
	return (1);
}
