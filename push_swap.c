/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/03 09:05:58 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <limits.h>

int	print_error_msg()
{
	ft_printf("Error\n");
	return (0);
}

int	has_duplicate(int *array, int size)
{
	int	i;
	int j;
	
	i = 0;
	j = 1;
	ft_printf("size is: %i\n", size);
	while (i < size)
	{
		ft_printf("while (%i < size)\n", i);
		ft_printf("j is = %i\n", j);
		while (j < size)
		{
			ft_printf("while (%i < size)\n", j);
			ft_printf("if (array[%i] == array[%j])\n", i, j);
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief: Takes an argument `stack a`, formatted as list of integers,
 *         Display list of instructions to sort `stack a` in ascending order
 *
*/
// TODO: Resolve bug with loop issues which checking for duplicates
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
		if (num == 0 && (argv[i][0] != '0' || argv[i][1] != '\0'))
			print_error_msg();
		if (num < INT_MIN || num > INT_MAX)
			print_error_msg();
		ft_printf("%i\n", i);
		duplicate_check_array[i-1] = (int)num;
		ft_printf("check_array[] = %i\n", duplicate_check_array[i-1]);
		if (i > 1 && has_duplicate(duplicate_check_array, i - 1)){
			ft_printf("Duplicates found!\n");
			return (0);
		}
		new_node = ft_lstnew((int)num);
		ft_lstadd_front(&head, new_node);
		i++;
	}
	if (has_duplicate(duplicate_check_array, argc - 1) == 1)
	{
		print_error_msg();
	}
	free(duplicate_check_array);
	return (1);
}
