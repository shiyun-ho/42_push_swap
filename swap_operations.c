/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:57 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/17 20:55:37 by hshi-yun         ###   ########.fr       */
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
	// TODO: Remove later - checker function
	t_list	*current;
	
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
	ft_printf("\nsa\n");

	// TODO: Remove later - checker function
	current = *stack_a;
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
	ft_printf("\n");
}
