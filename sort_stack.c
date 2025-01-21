/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/21 21:55:03 by hshi-yun         ###   ########.fr       */
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
// TODO: Direction is opposite, need to figure out the opposite of it
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
		
		a = (*stack_a)->next->next->content; // Last node: First number added
		b = (*stack_a)->next->content;
		c = (*stack_a)->content; // Last number added
		ft_printf("Before sorting (FILO):\n%i\n%i\n%i\n", c, b, a);
		// sort_three_numbers(stack_a, c, b, a);
		sort_three_numbers(stack_a, a, b, c);
	}
}

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
int		largest_no_position(t_list *first_node)
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

/*
 * @brief: Sorts when stack size <=5
 * @param: pointer to pointer of first node on top of stack
 */
void	sort_five_elements(t_list **stack_a, int size)
{
	int		largest_position;
	int		second_largest_position;
		
	// Find position of largest_node in linked list
	largest_position = largest_no_position(*stack_a);
	// Shift largest position to top of stack
	// Push to stack_b

	// Find position of largest node of stack_a
	second_largest_position = largest_no_position(*stack_a);
	// Shift largest position to top of stack
	// Push to stack_b
	
	// Sort remaining using sort_three_elements
	sort_three_elements(*stack_a, 3);
	
	// TODO: Push second largest, then largest element to stack_a
}
/**
 * @brief: Sorts stack from user input
 * @param: ``stack_a`` - Stack generated from user inputs
 */
void    sort_stack(t_list **stack_a)
{
    int     size;
    t_list  *current;

    //Create a temporary copy of inputs as stack a
    current = *stack_a;
    size = ft_lstsize(*stack_a);
    ft_printf("size = %i\n", size);
    // stack_b = NULL;
	
	//TODO: Implement sorting algorithm for 5 inputs, 100 inputs, more than 100
	if (size <= 3)
		sort_three_elements(stack_a, size);
	//TODO: 3, 5(12 moves), 100, 500
	else if (size <= 5)
		sort_five_elements(stack_a, size);
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
