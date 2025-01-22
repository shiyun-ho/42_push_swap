/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/22 22:56:39 by shiyun           ###   ########.fr       */
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
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else
	{
		int	a;
		int	b;
		int	c;
		
		a = (*stack_a)->next->next->content; // Last node: First number added is always last node
		b = (*stack_a)->next->content;
		c = (*stack_a)->content; // Last number added
		ft_printf("Before sorting (FILO):\n%i\n%i\n%i\n", c, b, a);
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
	int		position;

	position = 0;
	temp_node = first_node;
	largest_node = first_node;
	while (temp_node != NULL)
	{
		if (temp_node->content > largest_node->content)
		{
			position++;
			largest_node = temp_node;
		}
		temp_node = temp_node->next;
	}
	return (position);
}

/**
 * @brief: Shifts largest element to top of stack and pushes it to another stack
 * @param: stack_a
 */
void	shift_largest_to_top(t_list *stack_a, int largest_position, int size)
{
	if (largest_position == 1)
		sa(stack_a);
	else
	{
		if (largest_position == 2)
		{
			ra(stack_a);
			ra(stack_a);
		}
		if (largest_position == 3 && size != 3)
		{
			ra(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
		if (largest_position == size)
			rra(stack_a);
	}
	pb(stack_a);
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
	shift_largest_to_top(*stack_a, largest_position, size);
	if (size == 5)
	{
		second_largest_position = find_position_of_largest(*stack_a);
		shift_largest_to_top(*stack_a, second_largest_position, size);
	}
	sort_three_elements(*stack_a, 3);
	while (*stack_b)
	{
		pa(*stack_b);
		(*stack_b)->next;
	}
}
/**
 * @brief: Sorts stack from user input
 * @param: `stack_a` - Stack generated from user inputs
 */
void    sort_stack(t_list **stack_a)
{
    int     size;
    t_list  *current; //TODO: Remove
	t_list	**stack_b;

    current = *stack_a; //TODO: Remove
    size = ft_lstsize(*stack_a);
    ft_printf("size = %i\n", size);
    stack_b = NULL;
	
	if (size <= 3)
		sort_three_elements(stack_a, size);
	else if (size <= 5)
		sort_five_elements(stack_a, stack_b, size);
	// else if (size <= 100)
	// 	sort_hundred_elements(stack_a);
	// else
	// 	sort_thousand_elements(stack_a);
	// Printing all digits to allow checking
	
	// TODO: Remove later - checker function
	current = *stack_a;
	ft_printf("\n\nAfter sorting (FILO):\n");
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
}
