/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:57 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/16 09:21:16 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"

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
	//update top of stack to point to second node
	*stack_a = (*stack_a)->next;
	//make original top node to point to third node
	temporary_node->next = (*stack_a)->next;
	//make new top node point to original top node
	(*stack_a)->next = temporary_node;
	ft_printf("sa");
}
