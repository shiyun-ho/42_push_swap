/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 17:45:07 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int		is_sorted(t_list *stack_a)
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

/**
 * @brief: Sorts stack from user input
 * @param: `stack_a` - Stack generated from user inputs
 */
// void    sort_stack(t_list **stack_a)
// {
// 	int		size;
// 	t_list	*stack_b;

// 	stack_b = NULL;
// 	size = ft_lstsize(*stack_a);
// 	if (is_sorted(*stack_a))
// 		return ;
// 	if (size <= 3)
// 		sort_three_elements(stack_a, size);
// 	else if (size <= 5)
// 		sort_five_elements(stack_a, &stack_b, size);
// 	else 
// 	{
// 		quick_sort(stack_a);
// 		radix_sort(stack_a, &stack_b, size);
// 	}
// }


void    sort_stack(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	
	// TODO: REMOVE LATER
	ft_printf("Size: %i\n", size);
	ft_printf("Before sort...\n");

	ft_printf(">>> stack_a:\n");
	t_list *org_a = *stack_a;
	while (org_a)
	{
		ft_printf("%i\n", org_a->content);
		org_a = org_a->next;
	}

	ft_printf(">>> stack_b:\n");
	t_list *org_b = stack_b;
	while (org_b)
	{
		ft_printf("%i\n", org_b->content);
		org_b = org_b->next;
	}
	if (is_sorted(*stack_a))
		return ;
	if (size <= 3)
		sort_three_elements(stack_a, size);
	else if (size <= 5)
		sort_five_elements(stack_a, &stack_b, size);
	else 
	{
		quick_sort(stack_a);
		radix_sort(stack_a, &stack_b, size);
	}
	
	// TODO: REMOVE LATER
	ft_printf("\n\nCompleted sort...\n");
	ft_printf(">>> stack_a:\n");
	t_list *current_a = *stack_a;
	while (current_a)
	{
		ft_printf("%i\n", current_a->content);
		current_a = current_a->next;
	}

	ft_printf(">>> stack_b:\n");
	t_list *current_b = stack_b;
	while (current_b)
	{
		ft_printf("%i\n", current_b->content);
		current_b = current_b->next;
	}
}
