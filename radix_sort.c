/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:49:05 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/02/15 13:17:46 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
	@brief: Calculate total number of significant digit bits for largest rank
	@returns: Value in bits form
	@reason: Number of iterations & comparisons for radix sort
 */
int		bits_for_highest_rank(int rank)
{
	int		num_bits;

	num_bits = 0;
	while (rank > 0)
	{
		num_bits++;
		rank >>= 1;
	}

	return (num_bits);
}

/**
1) Calculate if element is closer to top or bottom.
a) Is target element closer to the top? - ra
b) Is target element closer to the bottom? - rra

2) Keep elements in stack_b until all bits have been processed.

3) 
a) Push elements with 0 in current bit to stack_b
b) Leave elements with 1 in current bit to stack_a
 */

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int		num_bits;
	int		bit;
	int		i;
	int		rank;

	num_bits = bits_for_highest_rank(size - 1);
	bit = 0;
	while (bit < num_bits)
	{
		i = 0;
		while (i < size)
		{
			rank = (*stack_a)->rank;
			if ((rank & (1 << bit)) == 0) //if bit == 0
				pb(stack_a, stack_b);
			else // if bit == 1
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}
