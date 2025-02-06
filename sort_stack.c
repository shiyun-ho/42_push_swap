/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/02 16:54:59 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
 * @brief: Sorts stack from user input
 * @param: `stack_a` - Stack generated from user inputs
 */
void    sort_stack(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);

	ft_printf("Stack: (Argument input from user)\n");
	print_all_nodes(*stack_a);

	if (size <= 3)
		sort_three_elements(stack_a, size);
	else if (size <= 5)
		sort_five_elements(stack_a, &stack_b, size);
	else 
	{
		*stack_a = reverse_stack(*stack_a);
		quick_sort(stack_a);
		radix_sort(stack_a, &stack_b, size);
		*stack_a = reverse_stack(*stack_a);
	}

	ft_printf("\n\nAfter sorting (FILO):\n");
	print_all_nodes(*stack_a);
	print_all_nodes_by_rank(*stack_a);
}
