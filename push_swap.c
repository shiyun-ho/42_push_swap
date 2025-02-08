/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/08 14:39:17 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

// TODO: Fix segmentation fault caused by improper handling of string input
// ISSUE: Reassigning `argv` directly to `ft_split()` result causes undefined behavior
// SOLUTION: Use a separate variable (e.g., `split_args`) to store split arguments instead of reassigning `argv`

// TODO: Ensure proper memory management for dynamically allocated split arguments
// ISSUE: Memory allocated by `ft_split()` is not freed, causing memory leaks
// SOLUTION: Free each element of `split_args` and then free the array itself at the end of the program

// TODO: Correctly update `argc` after splitting the string
// ISSUE: `argc` is not updated properly when processing split arguments
// SOLUTION: Update `argc` based on the number of elements in `split_args` using a helper function like `count_no_in_string()`

// TODO: Validate and process arguments consistently
// ISSUE: Accessing invalid memory or incorrect indices in `argv` after reassignment
// SOLUTION: Use `split_args` for validation and processing if `argv[1]` contains spaces

// TODO: Debug and test edge cases
// ISSUE: Potential null-pointer dereferences or invalid memory access
// SOLUTION: Add debug prints and use tools like `valgrind` to detect and fix memory errors

int		count_no_in_string(char *argv[])
{
	int		split_arg_count;

	split_arg_count = 0;
	while (argv[split_arg_count])
		split_arg_count++;
	return (split_arg_count);
}

char	**handle_string_input(char *argv[])
{
	int		no_of_inputs;
	char	**args_array;

	no_of_inputs = count_no_in_string(argv);
	*args_array = (int *)malloc((no_of_inputs - 1) * sizeof(int));
	args_array = ft_split(argv[1], ' ');
	if (!args_array)
		handle_error(NULL, NULL);
	return (args_array);
}

/**
 * @brief: Takes an argument `stack a`, formatted as list of integers,
 *         Display list of instructions to sort `stack a` in ascending order
*/
int	main(int argc, char *argv[])
{
	int		*duplicate_check_array;
	t_list	*head;
	char	**args_array;
	int		i;

	if (argc == 1)
		return (0);
	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		args_array = handle_string_input(argv);
		argc = count_no_in_string(args_array) + 1;
		argv = args_array;
	}
	i = 1;
	while (argv[i])
	{
		check_valid_argument(argv[i]);
		i++;
	}
	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
	{
		handle_error(duplicate_check_array, &head);
		exit(EXIT_FAILURE);
	}
	sort_stack(&head);
	ft_lstclear(&head, del_int);
	if (args_array)
	{
		i = 0;
		while (args_array[i])
		{
			free(args_array[i]);
			i++;
		}
		free(args_array);
	}
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	int		*duplicate_check_array;
// 	t_list	*head;
// 	char	**args_array;
// 	int		split_arg_count;
// 	int		i;

// 	if (argc == 1)
// 		return (0);
// 	args_array = NULL;
// 	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
// 	{
// 		// Split arguments into individual numbers
// 		args_array = ft_split(argv[1], ' ');
// 		// Exit if memory allocation fails
// 		if (!args_array)
// 			handle_error(NULL, NULL);

// 		// Count the number of split arguments
// 		split_arg_count = 0;
// 		while(args_array[split_arg_count])
// 			split_arg_count++;

// 		// Update argv with the split arguments
// 		argv = args_array;
// 		// Update argc to account for program name
// 		argc = split_arg_count + 1; 
// 	}
// 	i = 1;
// 	while (argv[i])
// 	{
// 		check_valid_argument(argv[i]);
// 		i++;
// 	}
// 	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
// 	{
// 		handle_error(duplicate_check_array, &head);
// 		ft_printf(">>>Exiting function...\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	ft_printf("\n");
// 	ft_printf(">>>Starting sorting of stack...\n");

// 	sort_stack(&head);

// 	ft_printf(">>>Clearing linked list nodes ...\n");
// 	ft_lstclear(&head, del_int);

// 	ft_printf(">>>Ending push_swap() program...\n");

// 	return (1);
// }
