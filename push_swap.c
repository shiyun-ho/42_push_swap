/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/01 14:28:12 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include "push_swap.h"
# include <limits.h>
# include <stdlib.h>

/**
 * @brief: Takes an argument `stack a`, formatted as list of integers,
 *         Display list of instructions to sort `stack a` in ascending order
*/
int	main(int argc, char *argv[])
{
	int		*duplicate_check_array;
	t_list	*head;
	int		i; 

	if (argc == 1)
		return (0);
	i = 1;
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

	sort_stack(&head);

	ft_printf(">>>Clearing linked list nodes ...\n");
	ft_lstclear(&head, del_int);

	ft_printf(">>>Ending push_swap() program...\n");

	return (1);
}
