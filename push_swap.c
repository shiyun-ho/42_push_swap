/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/05 15:14:06 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <limits.h>

void	del_int(int content)
{
	(void)content;
}

int		handle_error(int *array, t_list **node)
{
	ft_printf("Error\n");
	if (array)
		free(array);
	if (node)
		ft_lstclear(node, del_int);
	return (0);
}

int	has_duplicate(int *array, int size)
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

/**
 * @brief: Takes an argument `stack a`, formatted as list of integers,
 *         Display list of instructions to sort `stack a` in ascending order
 *
*/
int	main(int argc, char *argv[])
{
	int			i;
	long		num;
	int			*duplicate_check_array;
	t_list		*head;
	t_list		*new_node;
	
	if (argc == 1)
		return (0);
	i = 1;
	head = NULL;
	duplicate_check_array = malloc((argc - 1) * sizeof(int));
	if (!duplicate_check_array)
		return (0);
	while (i < argc)
	{
		num = ft_atol(argv[i]);	
		duplicate_check_array[i-1] = (int)num;
		new_node = ft_lstnew((int)num);
		if (!new_node)
			return (handle_error(duplicate_check_array, &head));
		ft_lstadd_front(&head, new_node);
		if ((num == 0 && (argv[i][0] != '0' || argv[i][1] != '\0')) ||
            (num < INT_MIN || num > INT_MAX) ||
            (has_duplicate(duplicate_check_array, i)))
            return handle_error(duplicate_check_array, &head);
		i++;
	}
	free(duplicate_check_array);
	ft_lstclear(&head, del_int);
	return (1);
}
