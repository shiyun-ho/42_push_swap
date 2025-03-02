/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/03/02 16:12:20 by hshi-yun         ###   ########.fr       */
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
	free(args[i]);
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

// validity check
void	check_if_valid(char ***argv)
{
	int		digit_checker;
	int		j;

	j = 0;
	digit_checker = 0;
	if ((*argv)[1][0] == '\0')
		handle_error(NULL, NULL);
	if (((*argv)[1][j] == '+' || (*argv)[1][j] == '-'))
		j++;
	while ((*argv)[1][j])
	{
		if (digit_checker > 0)
		{
			if ((*argv)[1][j] == '+' || (*argv)[1][j] == '-')
				handle_error(NULL, NULL);
		}
		if (ft_isdigit((*argv)[1][j]) == 0)
			handle_error(NULL, NULL);
		if (ft_isdigit((*argv)[1][j] == 1))
			digit_checker++;
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int		j;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') != NULL)
		{
			check_if_valid(&argv);
			argc = count_no_in_quoted_arg(argv);
			argv = process_quoted_arg(&argc, &argv);
		}
		else
		{
			j = 0;
			while (argv[1][j])
			{
				if (ft_isdigit(argv[1][j++]) == 0)
					handle_error(NULL, NULL);
			}
		}
	}
	handle_arguments(argc, argv);
	create_and_sort_linked_list(argc, argv);
	return (1);
}
