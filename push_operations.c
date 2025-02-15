/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:16:57 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 13:27:55 by hshi-yun         ###   ########.fr       */
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

    if (!(*stack_b))
        return ;
    top_node = *stack_b;
    *stack_b = (*stack_b)->next;
    top_node->next = *stack_a;
    *stack_a = top_node;

    ft_printf("pa\n");
}

/**
 * @brief: Pushes the top element from stack_a to stack_b
 * @param: Pointer to the pointer of the top element of stack_a
 * @param: Pointer to the pointer of the top element of stack_b
 */
void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_node;

    if (!(*stack_a))
        return ;
    top_node = *stack_a;
    *stack_a = (*stack_a)->next;
    top_node->next = *stack_b;
    *stack_b = top_node;

    ft_printf("pb\n");
}