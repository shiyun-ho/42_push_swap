/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:28:37 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 15:23:04 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	handle_error(int *array, t_list **node)
{
	write(2, "Error\n", 6);
	if (array)
		free(array);
	if (node)
		ft_lstclear(node, del_int);
	exit(EXIT_FAILURE);
}

int	has_duplicate(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(long num, char *arg, int *array, int index)
{
	if (num == 0 && (arg[0] != '0' || arg[1] != '\0'))
		return (0);
	if (has_duplicate(array, index))
		return (0);
	return (1);
}

int	create_linked_list(int argc, char *argv[], int **array, t_list **head)
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
		ft_lstadd_back(head, new_node);
		if (!validate_input(num, argv[i], *array, i))
			handle_error(*array, head);
		i++;
	}
	return (1);
}

/**
 * @brief: Checks for error in user input prior to insertion
*/
void	check_valid_argument(char *arg)
{
	int		j;

	j = 0;
	while (arg[j])
	{
		if (j == 0)
		{
			if (arg[j] == '+' || arg[j] == '-')
				j++;
		}
		if (!ft_isdigit(arg[j]))
			handle_error(NULL, NULL);
		j++;
	}
	if (j == 0 || (j == 1 && (arg[0] == '+' || arg[0] == '-')))
		handle_error(NULL, NULL);
}
