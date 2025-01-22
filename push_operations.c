/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:16:57 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/22 22:56:00 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"

/**
 * @brief: Pushes the top element from stack_b to stack_a
 * @param: Pointer to the pointer of the top element of stack_a
 * @param: Pointer to the pointer of the top element of stack_b
 */
void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_node;
    
    if (!(*stack_a))
        return ;
    top_node = *stack_a;
    *stack_a = (*stack_a)->next;
    top_node->next = *stack_b;
    *stack_b = top_node;
}


/**
 * @brief: Pushes the top element from stack_a to stack_b
 * @param: Pointer to the pointer of the top element of stack_a
 * @param: Pointer to the pointer of the top element of stack_b
 */
void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_node;

    if (!(*stack_b))
        return ;
    top_node = *stack_a;
    *stack_a = (*stack_a)->next;
    top_node->next = *stack_b;
    *stack_b = top_node;
}
// TODO: At the end of the execution of sorting, I should probably free stack_a, stack_b