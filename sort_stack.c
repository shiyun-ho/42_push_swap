/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:58:47 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/02 16:27:13 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/**
 * @brief: Algorithm for sorting three inputs
 * @params: a - first input [last in argument]
 * @params: b - second input
 * @params: c - third input [first in argument]
 */
/**
 * 1 2 3	a b c (V)
 * 2 3 1	b c a (V)
 * 3 1 2	c a b (V)
 * 2 1 3	b a c (V)
 * 3 2 1	c b a (V)
 * 1 3 2	a c b (V)
 */
void	sort_three_numbers(t_list **stack_a, int a, int b, int c)
{
	if (a < b && a < c)
	{
		if (b < c)
			return ;
		if (b > c)
			sa(stack_a);
	}
	if (b < a && b < c)
	{
		rra(stack_a);
		if (a < c)
			sa(stack_a);
	}
	if (c < a && c < b)
	{
		ra(stack_a);
		if (a > b)
			sa(stack_a);
	}
}

/**
 * @brief: Sorts when stack size <= 3
 * @param: stack
 */
void	sort_three_elements(t_list **stack_a, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else
	{
		a = (*stack_a)->next->next->content; // Last node: First number added 
		b = (*stack_a)->next->content;
		c = (*stack_a)->content; // Last number added
		sort_three_numbers(stack_a, a, b, c);
	}
	ft_printf("Starting sort_three_elements()...\n");
	t_list *current = *stack_a;
	while (current)
	{
		ft_printf("%i\n", current->content);
		current = current->next;
	}
}

/**
 * @brief: Find position of largest node in linked list
 * @returns: An integer on position
 */
/**
 * ./push_swap 1 2 3 4 5
 * 5 (*stack_a)
 * 4 (*stack_a)->next->next
 * 3 
 * 2
 * 1  
 * 5 (*stack_a)					 	    last_node (last argument)
 * 4 (*stack_a)->next
 * 3 (*stack_a)->next->next
 * 2 (*stack_a)->next->next->next
 * 1 (*stack_a)->next->next->next->next = first_node (first argument)
 */
int		find_position_of_largest(t_list *first_node)
{
	t_list	*temp_node;
	t_list	*largest_node;
	int		current_position;
	int		biggest_position;

	current_position = 0;
	biggest_position = 0;
	temp_node = first_node;
	largest_node = first_node;
	while (temp_node != NULL)
	{
		if (temp_node->content > largest_node->content)
		{
			biggest_position = current_position;
			largest_node = temp_node;
			ft_printf("temp_node is bigger than current largest node.\n");
			ft_printf(">>>>Largest Position: Index %i - %i\n", biggest_position, largest_node->content);
		}
		temp_node = temp_node->next;
		current_position++;
	}
	ft_printf("Ended search for largest position \n\n\n");
	return (biggest_position);
}

/**
 * @brief: Shifts largest element to top of stack and pushes it to another stack
 * @param: stack_a
 */
void	shift_largest_to_top(t_list **stack_a, t_list **stack_b, int largest_position, int size)
{
	int		count;

	count = largest_position;
	if (largest_position == 1)
		sa(stack_a);
	else
	{
		while ((count > 0) && largest_position != (size - 1))
		{
			ra(stack_a);
			count--;
		}
		if (largest_position == (size - 1))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

/*
 * @brief: Sorts when stack size <=5
 * @param: pointer to pointer of first node on top of stack
 */
void	sort_five_elements(t_list **stack_a, t_list **stack_b, int size)
{
	int		largest_position;
	int		second_largest_position;

	largest_position = find_position_of_largest(*stack_a);
	ft_printf("\nPosition of largest = %i\n", largest_position);
	shift_largest_to_top(stack_a, stack_b, largest_position, size);
	if (size == 5)
	{
		second_largest_position = find_position_of_largest(*stack_a);
		ft_printf("\nPosition of 2nd largest = %i\n", second_largest_position);
		shift_largest_to_top(stack_a, stack_b, second_largest_position, size);
	}
	sort_three_elements(stack_a, 3);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}

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

// void	sort_hundred_elements(t_list **stack_a, t_list **stack_b, int size)
// {
// 	quick_sort(stack_a);
// }


/**
 * @brief: Sorts stack from user input
 * @param: `stack_a` - Stack generated from user inputs
 */
void    sort_stack(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);

	ft_printf("Stack: (Argument input from user)\n");
	print_all_nodes(*stack_a);

	if (size <= 3)
		sort_three_elements(stack_a, size);
	else if (size <= 5)
		sort_five_elements(stack_a, &stack_b, size);
	else if (size <= 100)
	{
		*stack_a = reverse_stack(*stack_a);
		quick_sort(stack_a);
		// sort_hundred_elements(stack_a, &stack_b, size);
	}

	ft_printf("\n\nAfter sorting (FILO):\n");
	*stack_a = reverse_stack(*stack_a);
	print_all_nodes(*stack_a);
	print_all_nodes_by_rank(*stack_a);
}
