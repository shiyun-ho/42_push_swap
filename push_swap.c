/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/03/08 17:05:35 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

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
	free(args);
}

static void	handle_arguments(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		check_valid_argument(argv[i]);
		i++;
	}
}

static void	create_and_sort_linked_list(int argc, char **argv)
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

void	free_new_argv(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	main(int argc, char *argv[])
{
	int		new_argc;
	char	**new_argv;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == NULL)
			handle_no_space_arg(argv[1]);
		else
		{
			if (!validate_input_string(argv[1]))
				handle_error(NULL, NULL);
			new_argc = count_no_in_quoted_arg(argv);
			new_argv = process_quoted_arg(&new_argc, &argv);
			handle_arguments(new_argc, new_argv);
			create_and_sort_linked_list(new_argc, new_argv);
			free_new_argv(new_argv);
			return (1);
		}
	}
	handle_arguments(argc, argv);
	create_and_sort_linked_list(argc, argv);
	return (1);
}
