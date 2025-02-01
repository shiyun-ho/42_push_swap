/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:59:27 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/01 14:37:00 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft/libft.h"

// Argument checking utils
int		handle_error(int *array, t_list **node);
int		has_duplicate(int *array, int size);
int		validate_input(long num, char *arg, int *array, int index);
int		create_linked_list(int argc, char *argv[], int **array, t_list **head);
void	check_valid_argument(char *arg);

// Data structure operation utils
void	sort_stack(t_list **stack_a);
void	sa(t_list **stack_a);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif
