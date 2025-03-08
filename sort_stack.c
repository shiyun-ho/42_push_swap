/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/03/08 12:01:47 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*copy_stack(t_list *head)
{
	t_list	*new_head;
	t_list	*current;
	t_list	*node;

	new_head = NULL;
	current = head;
	while (current)
	{
		node = malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&new_head, del_int);
			exit(EXIT_FAILURE);
		}
		node->content = current->content;
		node->rank = 0;
		node->next = new_head;
		new_head = node;
		current = current->next;
	}
	return (new_head);
}

void	assign_ranks(t_list *stack, t_list *sorted_copy)
{
	t_list	*current;
	t_list	*sorted_node;
	int		index;

	current = stack;
	while (current)
	{
		sorted_node = sorted_copy;
		index = 0;
		while (sorted_node)
		{
			if (sorted_node->content == current->content)
			{
				current->rank = index;
				break ;
			}
			sorted_node = sorted_node->next;
			index++;
		}
		current = current->next;
	}
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

/**
 * @brief: Sorts stack from user input
 * @param: `stack_a` - Stack generated from user inputs
 */
void	sort_stack(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;
	t_list	*copy;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
	{
		ft_lstclear(stack_a, del_int);
		return ;
	}
	if (size <= 3)
		sort_three_elements(stack_a, size);
	else if (size <= 5)
		sort_five_elements(stack_a, &stack_b, size);
	else
	{
		copy = copy_stack(*stack_a);
		if (!copy)
			return ;
		quick_sort(&copy);
		assign_ranks(*stack_a, copy);
		ft_lstclear(&copy, del_int);
		radix_sort(stack_a, &stack_b, size);
	}
}
