/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/17 20:52:01 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include "push_swap.h"
# include <limits.h>

int		handle_error(int *array, t_list **node)
{
	ft_printf("Error\n");
	if (array)
		free(array);
	if (node)
		ft_lstclear(node, del_int);
	return (0);
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
		return (1);
	if (has_duplicate(array, index))
		return (1);
	return (0);
}
int		create_linked_list(int argc, char *argv[], int **array, t_list **head)
{
	int		i;
	long	num;
	t_list	*new_node;

	*array = malloc((argc - 1) * sizeof(int));
	if (!*array)
		return (0);

	i = 1;
	*head = NULL;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		(*array)[i - 1] = (int)num;
		if (num < INT_MIN || num > INT_MAX)
			return handle_error(*array, head);
		new_node = ft_lstnew((int)num);
		if (!new_node)
			return (0);
		ft_lstadd_front(head, new_node);
		if (validate_input(num, argv[i], *array, i))
			return (0);
		i++;
	}
	return (1);
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
	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
		return handle_error(duplicate_check_array, &head);
	free(duplicate_check_array);
	//TODO: Sort the stack with the nodes given
	sort_stack(&head);
	ft_lstclear(&head, del_int);
	return (1);
}
