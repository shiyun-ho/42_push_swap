/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:04:51 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/01/17 20:55:08 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"

/**
 * @brief: reverse rotate a: Shift all elements of stack_a down by one
 * @param: t_list **stack_a: point to pointer of top of stack
 */
void	rra(t_list **stack_a)
{
	t_list	*temporary_node;
	t_list	*second_last_node;
	t_list	*last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temporary_node = *stack_a;
	second_last_node = NULL;
	last_node = *stack_a;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	*stack_a = last_node;
	(*stack_a)->next = temporary_node;
	second_last_node->next = NULL;
	ft_printf(">>>rra\n");

	// TODO: Remove later - checker function
	t_list  *current = *stack_a;
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
}
