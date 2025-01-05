/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/01/05 17:16:42 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void    sort_stack(t_list **stack_a)
{
    // Store integers
    t_list  *current;
    t_list  *stack_b;

    //Create a temporary copy of inputs as stack a    
    current = *stack_a;
    stack_b = NULL;
    while (current)
    {
        ft_printf("%i\n", current->content);
        current = current->next;
    }
}