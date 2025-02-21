/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:57 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 13:40:12 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

/**
 * @brief: Swaps top two elements in stack_a
 * @note: Does nothing if there is one or no elements
 * @param: t_list **stack_a: pointer to pointer to the top of the stack
 */
void	sa(t_list **stack_a)
{
	int		size;
	t_list	*temporary_node;

	size = ft_lstsize(*stack_a);
	if (size <= 1 || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temporary_node = *stack_a;
	*stack_a = (*stack_a)->next;
	temporary_node->next = (*stack_a)->next;
	(*stack_a)->next = temporary_node;
	ft_printf("sa\n");
}
