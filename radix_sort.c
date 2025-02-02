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
	@brief: Implementation of radix sort
	@steps:
	1) Determine number of bits to represent largest rank
	2) From LSB to MSB:
		- For each bit, push elements with 0 to stack_b
		- For each bit, push elements with 1 to stack_a
		- Restore all elements from stack_b to stack_a
 */