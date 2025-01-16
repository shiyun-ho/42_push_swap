/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:56:42 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/16 09:21:17 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"

// TODO: Implement ra, rra
/**
 * @brief: Shifts all elements of stack_a by one
 * @note: First element becomes last
 * @param: t_list **stack_a: pointer to pointer of top of the stack
 */
void	ra(t_list **stack_a)
{
	int		size;
	t_list	*temporary_node;
	t_list	*last_node;

	size = ft_lstsize(*stack_a);
	if (size <= 1 || *stack_a == NULL || (*stack_a) == NULL)
		return ;
	// Save the top node
	temporary_node = *stack_a;
	// Update top node to point to second node
	*stack_a = (*stack_a)->next;
	// Traverse to bottom of the stack
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	// Reconnect top node to the bottom node
	last_node->next = temporary_node;
	temporary_node->next = NULL;
	ft_printf("ra");
}
