/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:01:53 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/02/02 16:03:34 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

t_list	*reverse_stack(t_list *head)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = head;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

void	print_all_nodes(t_list *node)
{
	while (node)
	{
		ft_printf("%d -> ", node->content);
		node = node->next;
	}
	ft_printf("NULL\n");
}