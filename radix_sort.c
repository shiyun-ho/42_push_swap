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
int	bits_for_highest_rank(int rank)
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

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	num_bits;
	int	bit;
	int	i;
	int	rank;

	num_bits = bits_for_highest_rank(size - 1);
	bit = 0;
	while (bit < num_bits)
	{
		i = 0;
		while (i < size)
		{
			rank = (*stack_a)->rank;
			if ((rank & (1 << bit)) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
		bit++;
	}
}
