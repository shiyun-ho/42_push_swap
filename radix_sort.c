/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:49:05 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/02/02 16:51:12 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief: Calculate bits for largest rank
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

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int		num_bits;
	int		bit;
	int		i;
	int		rank;

	num_bits = bits_for_highest_rank(size - 1);
	bit = 0;
	i = 0;
	while (bit < num_bits)
	{
		ft_printf("Processing bit: %d\n", bit);
		
		// TODO: Traverse through all the elements in the linkedlist (as stack)
		while (i < size)
		{
			rank = (*stack_a)->next;
			if ((rank) & (1 << bit)) == 0) //if bit == 0
				//Action
			else // if bit == 1
				//Action: Move the element down by rotating
			i++;
		}
		// TODO: Restore elements from stack_b to stack_a
		while (*stack_b)
		{
			// Push to stack_b 
			pa(*stack_b);
			*stack_b = (*stack_b)->next;
		}
		bit++;
	}		
}