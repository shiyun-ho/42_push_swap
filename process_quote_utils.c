/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quote_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:52:39 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 12:00:08 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

char	**handle_string_input(char *arg)
{
	char	**args_array;

	args_array = ft_split(arg, ' ');
	if (!args_array)
		handle_error(NULL, NULL);
	return (args_array);
}

int	count_no_in_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_no_in_quoted_arg(char *argv[])
{
	int		split_count;
	char	**args_array;
	int		total_no;

	args_array = handle_string_input(argv[1]);
	split_count = count_no_in_array(args_array);
	free_split(args_array);
	total_no = split_count;
	if (argv[1] && argv[1][0] != '\0' && split_count == 0)
		total_no = 1;
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
	if (!new_argv)
		handle_error(NULL, NULL);
	new_argv[0] = (*argv)[0];
	i = 0;
	while (i < split_count)
	{
		new_argv[i + 1] = ft_strdup(args_array[i]);
		if (!new_argv[i + 1])
			handle_error(NULL, NULL);
		i++;
	}
	new_argv[split_count + 1] = NULL;
	*argc = split_count + 1;
	*argv = new_argv;
	free_split_args(args_array);
	return (new_argv);
}
