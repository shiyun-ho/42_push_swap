/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2024/12/28 21:53:23 by shiyun           ###   ########.fr       */
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
	while (i < size)
	{
		while (j < size)
		{
			if (array[i] == array[j])
				return 1;
			j++;
		}
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
		if (num == 0 && (argv[i][0] != '0' || argv[i][1] != '\0'))
			print_error_msg();
		if (num < INT_MIN || num > INT_MAX)
			print_error_msg();
		duplicate_check_array[i-1] = (int)num;
		new_node = ft_lstnew((int)num);
		ft_lstadd_front(&head, new_node);
		i++;
	}
	for (int i = 0; i < argc; i++){
		ft_printf("%i\n", duplicate_check_array[i]);
	}
	if (has_duplicate(duplicate_check_array, argc - 1) == 1)
	{
		print_error_msg();
	}
	free(duplicate_check_array);
	return (1);
}
