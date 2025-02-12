/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/12 21:46:25 by hshi-yun         ###   ########.fr       */
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

int		count_no_in_quoted_arg(char *argv[])
{
	int		split_count;
	char	**args_array;
	int		total_no;

	args_array = handle_string_input(argv[1]);
	split_count = count_no_in_array(args_array);
	free(args_array);
	total_no = split_count + 1;
	return (total_no);
}

char	**process_quoted_arg(int *argc, char ***argv)
{
	char	**args_array;
	char	**new_argv;
	int		split_count;
	int		i;

	args_array = handle_string_input((*argv)[1]);
	split_count = count_no_in_array(args_array);

	new_argv = (char **)malloc((split_count + 2) * sizeof(char *));
	new_argv[0] = (*argv)[0];

	i = 0;
	while (i < split_count)
	{
		new_argv[i + 1] = args_array[i];
		i++;
	}
	new_argv[split_count + 1] = NULL;

	*argc = split_count + 1;
	*argv = new_argv;

	free(args_array);
	return (new_argv);
}

static void		handle_arguments(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		check_valid_argument(argv[i]);
		i++;
	}
}

static void		create_and_sort_linked_list(int argc, char **argv)
{
	int		*duplicate_check_array;
	t_list	*head;

	duplicate_check_array = NULL;
	head = NULL;
	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
	{
		handle_error(duplicate_check_array, &head);
		exit(EXIT_FAILURE);
	}
	sort_stack(&head);
	ft_lstclear(&head, del_int);
	free(duplicate_check_array);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		argc = count_no_in_quoted_arg(argv);
		argv = process_quoted_arg(&argc, &argv);
	}
	handle_arguments(argc, argv);
	create_and_sort_linked_list(argc, argv);
	return (1);
}









/**
ACCURATE BUT IDK HOW TO REFACTOR
 */
// int	main(int argc, char *argv[])
// {
// 	int		*duplicate_check_array;
// 	t_list	*head;
// 	char	**args_array;
// 	char	**new_argv;
// 	int		i;

// 	if (argc == 1)
// 		return (0);

// 	args_array = NULL;
// 	new_argv = NULL;

// 	if (argc >= 2 && ft_strchr(argv[1], ' ') != NULL)
// 	{
// 		args_array = handle_string_input(argv[1]);
// 		int split_count = count_no_in_array(args_array);
// 		int new_argc = split_count + 1;

// 		new_argv = (char **)malloc((new_argc + 1) * sizeof(char*));
// 		if (!new_argv)
// 			handle_error(NULL, NULL);

// 		new_argv[0] = argv[0];
// 		i = 0;
// 		while (i < split_count)
// 		{
// 			new_argv[i + 1] = args_array[i];
// 			i++;
// 		}
// 		new_argv[new_argc] = NULL;

// 		argc = new_argc;
// 		argv = new_argv;
// 	}
// 	i = 1;
// 	while (i < argc)
// 	{
// 		check_valid_argument(argv[i]);
// 		i++;
// 	}
// 	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
// 	{
// 		handle_error(duplicate_check_array, &head);
// 		exit(EXIT_FAILURE);
// 	}

// 	sort_stack(&head);

// 	ft_lstclear(&head, del_int);
// 	free(duplicate_check_array);

// 	if (args_array)
// 	{
// 		i = 0;
// 		while (args_array[i])
// 		{
// 			free(args_array[i]);
// 			i++;
// 		}
// 		free(args_array);
// 	}
// 	if (new_argv)
// 		free(new_argv);
// 	return (1);
// }