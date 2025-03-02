/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:18 by shiyun            #+#    #+#             */
/*   Updated: 2025/03/02 13:38:28 by hshi-yun         ###   ########.fr       */
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

	ft_printf("Entered create_and_sort_linked_list()\n");
	duplicate_check_array = NULL;
	head = NULL;
	// if it fails duplicate check
	if (!create_linked_list(argc, argv, &duplicate_check_array, &head))
	{
		ft_printf("Entering check prior to creation of linked list\n");
		// free(argv);
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
