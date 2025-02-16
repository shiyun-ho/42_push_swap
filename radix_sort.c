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

void print_stack(t_list *stack, char name) {
    printf("Stack %c: ", name);
    while (stack) {
        ft_printf("%d ", stack->rank); // Assuming `rank` is the value you want to print
        stack = stack->next;
    }
    ft_printf("\n");
}

void radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int num_bits;
    int bit;
    int i;
    int rank;

    num_bits = bits_for_highest_rank(size - 1); // Calculate the number of bits needed
    bit = 0;

	printf("Checking rank for first node: %i position for value %i\n", (*stack_a)->rank, (*stack_a)->content);
    while (bit < num_bits)
    {
        i = 0;
        while (i < size)
        {
			rank = (*stack_a)->rank; // Get the rank of the top node in stack A

            // Print the state of both stacks BEFORE the operation
            printf("Before operation (bit %d, i %d):\n", bit, i);
            print_stack(*stack_a, 'A');
            print_stack(*stack_b, 'B');
			

            if ((rank & (1 << bit)) == 0) // If the current bit is 0
            {
                pb(stack_a, stack_b); // Push to stack B
                printf("After pb:\n");
            }
            else // If the current bit is 1
            {
                ra(stack_a); // Rotate stack A
                printf("After ra:\n");
            }

            // Print the state of both stacks
            print_stack(*stack_a, 'A');
            print_stack(*stack_b, 'B');

            i++;
        }

        // Move all elements back from stack B to stack A
        while (*stack_b)
        {
            pa(stack_a, stack_b); // Push back to stack A
            printf("After pa:\n");

            // Print the state of both stacks
            print_stack(*stack_a, 'A');
            print_stack(*stack_b, 'B');
        }

        bit++; // Move to the next bit
    }
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

// void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
// {
// 	int		num_bits;
// 	int		bit;
// 	int		i;
// 	int		rank;

// 	num_bits = bits_for_highest_rank(size - 1);
// 	bit = 0;
// 	while (bit < num_bits)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			rank = (*stack_a)->rank;
// 			if ((rank & (1 << bit)) == 0) //if bit == 0
// 				pb(stack_a, stack_b);
// 			else // if bit == 1
// 				ra(stack_a);
// 			i++;
// 		}
// 		while (*stack_b)
// 			pa(stack_a, stack_b);
// 		bit++;
// 	}
// }
