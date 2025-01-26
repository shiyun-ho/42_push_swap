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

    if (!(*stack_b))
        return ;
    top_node = *stack_b;
    *stack_b = (*stack_b)->next;
    top_node->next = *stack_a;
    *stack_a = top_node;

    ft_printf("\n>>>pa\n");
    ft_printf("\npushed %i from stack_b to stack_a\n", top_node->content);

    ft_printf("\nstack_a after pa:\n");
    t_list *current_a = *stack_a;
    while (current_a)
    {
        ft_printf("%i\n", current_a->content);
        current_a = current_a->next;
    }

    ft_printf("\nstack_b after pa:\n");
    t_list *current_b = *stack_b;
    while (current_b)
    {
        ft_printf("%i\n", current_b->content);
        current_b = current_b->next;
    }
    ft_printf("\n");
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

    ft_printf("\n>>>pb\n");
    ft_printf("pushed %i from stack_a to stack_b\n", top_node->content);

    // Print stack_a and stack_b after the operation (for debugging)
    ft_printf("\nstack_a after pb:\n");
    t_list *current_a = *stack_a;
    while (current_a)
    {
        ft_printf("%i\n", current_a->content);
        current_a = current_a->next;
    }

    ft_printf("\nstack_b after pb:\n");
    t_list *current_b = *stack_b;
    while (current_b)
    {
        ft_printf("%i\n", current_b->content);
        current_b = current_b->next;
    }
    ft_printf("\n");
}