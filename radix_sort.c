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

// void	sort_hundred_elements(t_list **stack_a, t_list **stack_b, int size)
// {
// // 	// TODO: Decipher the algorithm for sorting hundred elements
// // 	/**
// // 	A. Preprocessing: Index Mapping
// // 	a) Add `int index` to struct (Done)
// // 	b) Sort the original linked list. (Quick Sort algorithm) (Done)
// // 	c) Assign each number its index in the sorted list. (Done)

// // 	B. Move bigger half to stack_b with bitwise operation as a criteria
// // 	a) Check Most Significant Bit (MSB) of each index
// // 	b) Push elements with a 0 in MSB to stack_b, 1 to stack_a

// // 	C. Divide and Conquer - Sort both simultaneously
// // 	a) Start by least significant bit in bitwise of all numbers in stack_a
// // 	b) If LSB = 1, move to top 
// // 	c) If LSB = 1, move to stack_b
// // 	d) Move all elements from stack_b to stack_a
// // 	e) Evaluate next most significant bit
// // 	f) Repeat steps #b to #e until last bit.  
// // 	 */
// }

/**
	@brief: Implementation of radix sort
	@steps:
	1) Determine number of bits to represent largest rank
	2) From LSB to MSB:
		- For each bit, push elements with 0 to stack_b
		- For each bit, push elements with 1 to stack_a
		- Restore all elements from stack_b to stack_a
 */
/**
	@brief: Calculate bits for largest rank
	@returns: Value in bits form
 */
int		bits_for_highest_rank(int value)
{
	int		bit_value;


	return (bit_value);
}