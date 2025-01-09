/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/09 09:00:31 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
	 * @param:
	 * 2
	 * 3
	 * 1
	 * @returns:
	 * 1
	 * 2
	 * 3
	 */
/**
 * @brief: Sorts when stack size <= 3
 * @param: stack
 */
void	sort_small_input(t_list **stack_a, int size)
{
	if (size == 1)
		return (0);
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);	//swap first two elements in stack_a
	}
	else
	{
		int	a;
		int	b;
		int	c;
		
		a = (*stack_a)->content;
		b = (*stack_a)->next->content;
		c = (*stack_a)->next->next->content;

/**
 * Scenarios (ascending)
 * a, b, c (V)
 * a, c, b 
 * b, c, a (V)
 * b, a, c
 * c, a, b 
 * c, b, a (V)
 */
		if (a < b && b < c)	// a, b, c
			return ; 
		if (a > b && a > c)
		{
			ra(stack_a); // c, b, a
			if (b < c) // b, c, a
				ra(stack_a); 
		}
		else if ()
		{
			
		}
	}
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
	
	//TODO: Implement sorting algorithm for 3 inputs, 100 inputs, more than 100
	if (size <= 3)
		sort_small_input(stack_a, size);
	else if (size <= 100)
		sort_medium_input(stack_a);
	else
		sort_large_input(stack_a);
	//TODO: Print out instruction for each move
	
	// Printing all digits to allow checking 
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
}