/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/11 21:57:25 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	count_no_in_array(char **array)
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

void	free_split_args(char **args)
{
	int		i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
}

// void	reassign_arguments(char **argv, char **new_argv, int split_count)
// {
// 	int		i;

// 	i = 0;
// 	while (i < split_count)
// 	{
// 		new_argv[i + 1] = argv[i];
// 		i++;
// 	}
// 	new_argv[split_count + 1] = NULL;
// }

// char	**process_quoted_arg(char *input, int *argc, char **argv)
// {
// 	char	**split_args;
// 	char	**new_argv;
// 	int		split_count;

// 	split_args = handle_string_input(input);
// 	if (!split_args)
// 		handle_error(NULL, NULL);
// 	split_count = count_no_in_array(split_args);
// 	new_argv = (char **)malloc((split_count + 2) * sizeof(char *));
// 	if (!new_argv)
// 	{
// 		free_split_args(split_args);
// 		handle_error(NULL, NULL);
// 	}
// 	new_argv[0] = argv[0];
// 	reassign_arguments(argv, new_argv, split_count);
// 	*argc = split_count + 1;
// 	free(split_args);
// 	return (new_argv);
// }

// /**
//  * @brief: Takes an argument `stack a`, formatted as list of integers,
//  *         Display list of instructions to sort `stack a` in ascending order
// */
// int	main(int argc, char *argv[])
// {
// 	int		*duplicate_check_array;
// 	t_list	*head;
// 	char	**new_argv;
// 	int		i;

// 	if (argc == 1)
// 		return (0);
// 	new_argv = NULL;
// 	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
// 		argv = process_quoted_arg(argv[1],&argc, argv);
// 	i = 1;
// 	while (i < argc)
// 		check_valid_argument(argv[i++]);
// 	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
// 	{
// 		handle_error(duplicate_check_array, &head);
// 		exit(EXIT_FAILURE);
// 	}
// 	sort_stack(&head);
// 	ft_lstclear(&head, del_int);
// 	free(duplicate_check_array);
// 	if (new_argv)
// 		free(new_argv);
// 	return (1);
// }

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

