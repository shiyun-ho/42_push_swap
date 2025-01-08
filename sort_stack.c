/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/08 08:54:45 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
 * @brief: Sorts stack from user input 
 * @param: ``stack_a`` - Stack generated from user inputs
 */
void    sort_stack(t_list **stack_a)
{
    // Store integers
    t_list  *current;
    // t_list  *stack_b;

    //Create a temporary copy of inputs as stack a    
    current = *stack_a;
    // stack_b = NULL;
    while (current)
    {
        ft_printf("%i\n", current->content);
        /**
         * @brief: Sort numbers in ascending number in stack a
         * @param:
         * 2
         * 3
         * 1
         * @example:
         * 1
         * 2
         * 3
         */
        //TODO: Implement sorting algorithm
        //TODO: Print out instruction for each move
        current = current->next;
    }
}