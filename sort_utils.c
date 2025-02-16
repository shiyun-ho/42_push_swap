/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 15:03:27 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
 * @brief: Algorithm for sorting three inputs
 * @params: a - first input
 * @params: b - second input
 * @params: c - third input
 */
void	sort_three_numbers(t_list **stack_a)
{
	int a;
	int b;
	int c;
	
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
    if (a < b && b < c) //123
        return;
    if (a < c && c < b) //132
    {
        sa(stack_a);
        ra(stack_a);
    }
    if (b < a && a < c) //213 
        sa(stack_a);
    if (c < a && a < b) //231
        rra(stack_a);
    if (b < c && c < a) //312
        ra(stack_a);
    if (c < b && b < a) //321
    {
        sa(stack_a);
        rra(stack_a);
    }
}

/**
 * @brief: Sorts when stack size <= 3
 * @param: stack
 */
void	sort_three_elements(t_list **stack_a, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else
	{
		sort_three_numbers(stack_a);
	}
}

/**
 * @brief: Find position of largest node in linked list
 * @returns: An integer on position
 */
 int		find_position_of_smallest(t_list *first_node)
{
	t_list	*temp_node;
	t_list	*smallest_node;
	int		current_position;
	int		smallest_position;

	current_position = 0;
	smallest_position = 0;
	temp_node = first_node;
	smallest_node = first_node;
	while (temp_node != NULL)
	{
		if (temp_node->content < smallest_node->content)
		{
			smallest_position = current_position;
			smallest_node = temp_node;
		}
		temp_node = temp_node->next;
		current_position++;
	}
	return (smallest_position);
}

/**
 * @brief: Shifts smallest element to top of stack and pushes it to another stack
 * @param: stack_a, stack_b, position (largest position), size
 */
void	shift_top(t_list **stack_a, t_list **stack_b, int position, int size)
{
	int		count;

	count = position;
	if (position == 1)
		sa(stack_a);
	else
	{
		while ((count > 0) && position != (size - 1))
		{
			ra(stack_a);
			count--;
		}
		if (position == (size - 1))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

/*
 * @brief: Sorts when stack size <=5
 * @param: pointer to pointer of first node on top of stack
 */
 void	sort_five_elements(t_list **stack_a, t_list **stack_b, int size)
{
	int		smallest_position;
	int		second_smallest_position;

	smallest_position = find_position_of_smallest(*stack_a);
	// ft_printf("Position of smallest node: %i\n", smallest_position);
	shift_top(stack_a, stack_b, smallest_position, size);
	if (size == 5)
	{
		second_smallest_position = find_position_of_smallest(*stack_a);
		// ft_printf("Position of second smallest node: %i\n", second_smallest_position);
		shift_top(stack_a, stack_b, second_smallest_position, size);
	}
	sort_three_elements(stack_a, 3);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
