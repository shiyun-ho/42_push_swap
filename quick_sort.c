/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:34:53 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/02/02 15:44:46 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include "push_swap.h"

/** 
	@brief: Implementation of Quick Sort Algorithm
	@note: Time Complexity: O(n log n)
	@steps:
	1 - Select a pivot
	2 - Partition around the pivot
	3 - Recursively sort sublist
	4 - Join the sorted sublist back together
	@reference: https://ideone.com/927LhE
*/

void    print_nodes(t_list *node)
{
	while (node)
	{
		ft_printf("%d -> ", node->content);
		node = node->next;
	}
	ft_printf("NULL\n");
}

/**
	@brief: Paritions list into lesser than and greater than sublists
 */

void	partition_list(t_list *pivot, t_list **lt_sublist, t_list **gt_sublist)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = pivot->next;
	while (current_node)
	{
		next_node = current_node->next;
		if (pivot->content > current_node->content)
		{
			current_node->next = *lt_sublist;
			*lt_sublist = current_node;
		}
		else
		{
			current_node->next = *gt_sublist;
			*gt_sublist = current_node;
		}
		current_node = next_node;
	}
	pivot->next = NULL;
	// Debug prints
    ft_printf("\n\nPivot: %i\n", pivot->content);
    ft_printf("Less than sublist:\n");
    print_nodes(*lt_sublist);
    ft_printf("Greater than or equal sublist:\n");
    print_nodes(*gt_sublist);
}


t_list	*combine_sublists(t_list *pivot, t_list *lt_list, t_list *gt_list)
{
	t_list	*sorted_gt_tail;
	t_list	*sorted_lt_tail;

	pivot->next = gt_list;
	
	sorted_gt_tail = pivot;

	while (sorted_gt_tail && sorted_gt_tail->next)
		sorted_gt_tail = sorted_gt_tail->next;

	if (lt_list != NULL)
	{
		sorted_lt_tail = lt_list;
		while (sorted_lt_tail && sorted_lt_tail->next)
			sorted_lt_tail = sorted_lt_tail->next;
		sorted_lt_tail->next = pivot;
		return (lt_list);
	}

	return (pivot);
}

/**
	@brief: Sorts linked list with quick sort recursively
 */

t_list	*quick_sort(t_list **head_ref)
{
	t_list	*pivot;
	t_list	*lt_sublist;
	t_list	*gt_sublist;
	t_list	*current;
	int		i;

	pivot = (*head_ref);
	lt_sublist = NULL;
	gt_sublist = NULL;
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return (*head_ref);
	ft_printf("Base case reached: head_ref = %p\n", (void *)*head_ref);
	partition_list(pivot, &lt_sublist, &gt_sublist);
	
	ft_printf("\n\n>>>Starting recursive call of quick sort on lt and gt sublist:\n\n");
	
	ft_printf("Sorting less than sublist:\n");
	print_nodes(lt_sublist);
	quick_sort(&lt_sublist);
	ft_printf("After sorting:\n");
	print_nodes(lt_sublist);
	
	ft_printf("Sorting less than sublist:\n");
	print_nodes(gt_sublist);
	quick_sort(&gt_sublist);
	ft_printf("After sorting:\n");
	print_nodes(gt_sublist);
	
	*head_ref = combine_sublists(pivot, lt_sublist, gt_sublist);
	ft_printf("Combined sublists:\n");
	print_nodes(*head_ref);
	
	current = *head_ref;
	i = 0;
	while (current)
	{
		current->rank = i;
		current = current->next;
		i++;
	}
	return (*head_ref);
}
