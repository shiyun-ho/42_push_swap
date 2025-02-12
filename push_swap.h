/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:59:27 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/12 21:56:50 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

// Parsing processing utils
char	**handle_string_input(char *arg);
int		count_no_in_array(char **array);
int		count_no_in_quoted_arg(char *argv[]);
char	**process_quoted_arg(int *argc, char ***argv);

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

// Sort utils
void	sort_three_numbers(t_list **stack_a, int a, int b, int c);
void	sort_three_elements(t_list **stack_a, int size);
int		find_position_of_largest(t_list *first_node);
void	shift_top(t_list **stack_a, t_list **stack_b, int position, int size);
void	sort_five_elements(t_list **stack_a, t_list **stack_b, int size);

// Quick sort utils
void	partition_list(t_list *pivot, t_list **lt_sublist, t_list **gt_sublist);
t_list	*combine_sublists(t_list *pivot, t_list *lt_list, t_list *gt_list);
t_list	*quick_sort(t_list **head_ref);

// Stack utils
t_list	*reverse_stack(t_list *head);
void	print_all_nodes(t_list *node);
void	print_all_nodes_by_rank(t_list *node);

// Radis sort utils
int		bits_for_highest_rank(int rank);
void	radix_sort(t_list **stack_a, t_list **stack_b, int size);

#endif
