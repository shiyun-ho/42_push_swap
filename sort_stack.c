/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/15 22:14:26 by shiyun           ###   ########.fr       */
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
void	sort_three_numbers(t_list **stack_a, int a, int b, int c)
{
	if (a < b && b < c)	// a, b, c
		return ;
	else if (a > b && a < c)
		sa(stack_a); // b, a, c
	else if (a < b && a > c)
	{
		ra(stack_a); // b, c, a
		if (b > c)
			sa(stack_a); // c, b, a
	}
	else if (a < b && b > c)
	{
		rra(stack_a); // c, a, b
		if (a < c) // a, c, b
			sa(stack_a);
	}
}
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
			sa(stack_a);
	}
	else
	{
		int	a;
		int	b;
		int	c;
		
		a = (*stack_a)->content;
		b = (*stack_a)->next->content;
		c = (*stack_a)->next->next->content;
		sort_three_numbers(stack_a, a, b, c);
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
	
	//TODO: Implement sorting algorithm for 5 inputs, 100 inputs, more than 100
	if (size <= 3)
		sort_small_input(stack_a, size);
	//TODO: 3, 5(12 moves), 100, 500
	else if (size <= 5)
		sort_medium_input(stack_a, size);
	else if (size <= 100)
		sort_large_input(stack_a);
	else
		sort_mass_input(stack_a);
	//TODO: Print out instruction for each move
	
	// Printing all digits to allow checking 
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
}
