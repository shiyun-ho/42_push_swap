/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/08 20:25:38 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int		count_no_in_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**handle_string_input(char *arg)
{
	char	**args_array;

	args_array = ft_split(arg, ' ');
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
	char	**new_argv;
	int		i;

	if (argc == 1)
		return (0);

	args_array = NULL;
	new_argv = NULL;

	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		args_array = handle_string_input(argv[1]);
		int split_count = count_no_in_array(args_array);
		int new_argc = split_count + 1;
		
		new_argv = (char **)malloc((new_argc + 1) * sizeof(char*));
		if (!new_argv)
			handle_error(NULL, NULL);
		
		new_argv[0] = argv[0];
		i = 0;
		while (i < split_count)
		{
			new_argv[i + 1] = args_array[i];
			i++;
		}
		new_argv[new_argc] = NULL;

		argc = new_argc;
		argv = new_argv;
	}
	i = 1;
	while (i < argc)
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
	free(duplicate_check_array);

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
	if (new_argv)
		free(new_argv);
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
