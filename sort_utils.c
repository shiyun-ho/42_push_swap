/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 13:41:49 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
 * @brief: Algorithm for sorting three inputs
 * @params: a - first input [last in argument]
 * @params: b - second input
 * @params: c - third input [first in argument]
 */
/**
 * 1 2 3	a b c (V)
 * 2 3 1	b c a (V)
 * 3 1 2	c a b (V)
 * 2 1 3	b a c (V)
 * 3 2 1	c b a (V)
 * 1 3 2	a c b (V)
 */
void	sort_three_numbers(t_list **stack_a, int a, int b, int c)
{
	if (a < b && a < c)
	{
		if (b < c)
			return ;
		if (b > c)
			sa(stack_a);
	}
	if (b < a && b < c)
	{
		rra(stack_a);
		if (a < c)
			sa(stack_a);
	}
	if (c < a && c < b)
	{
		ra(stack_a);
		if (a > b)
			sa(stack_a);
	}
}

/**
 * @brief: Sorts when stack size <= 3
 * @param: stack
 */
void	sort_three_elements(t_list **stack_a, int size)
{
	int		a;
	int		b;
	int		c;

	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else
	{
		a = (*stack_a)->next->next->content; // Last node: First number added 
		b = (*stack_a)->next->content;
		c = (*stack_a)->content; // Last number added
		sort_three_numbers(stack_a, a, b, c);
	}
}

/**
 * @brief: Find position of largest node in linked list
 * @returns: An integer on position
 */
/**
 * ./push_swap 1 2 3 4 5
 * 5 (*stack_a)
 * 4 (*stack_a)->next->next
 * 3 
 * 2
 * 1  
 * 5 (*stack_a)					 	    last_node (last argument)
 * 4 (*stack_a)->next
 * 3 (*stack_a)->next->next
 * 2 (*stack_a)->next->next->next
 * 1 (*stack_a)->next->next->next->next = first_node (first argument)
 */
int		find_position_of_largest(t_list *first_node)
{
	t_list	*temp_node;
	t_list	*largest_node;
	int		current_position;
	int		biggest_position;

	current_position = 0;
	biggest_position = 0;
	temp_node = first_node;
	largest_node = first_node;
	while (temp_node != NULL)
	{
		if (temp_node->content > largest_node->content)
		{
			biggest_position = current_position;
			largest_node = temp_node;
		}
		temp_node = temp_node->next;
		current_position++;
	}
	return (biggest_position);
}

/**
 * @brief: Shifts largest element to top of stack and pushes it to another stack
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
	int		largest_position;
	int		second_largest_position;

	largest_position = find_position_of_largest(*stack_a);
	shift_top(stack_a, stack_b, largest_position, size);
	if (size == 5)
	{
		second_largest_position = find_position_of_largest(*stack_a);
		shift_top(stack_a, stack_b, second_largest_position, size);
	}
	sort_three_elements(stack_a, 3);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
