/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:16:19 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/10 21:20:11 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	handle_no_space_arg(char *str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			handle_error(NULL, NULL);
		i++;
	}
	num = ft_atol(str);
	if (num)
	{
		if (num < INT_MIN || num > INT_MAX)
			handle_error(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	handle_error(NULL, NULL);
}

int	is_valid_number(const char *str)
{
	int		i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_consecutive_spaces(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == '\0')
			return (1);
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	has_duplicates_in_str(char **numbers, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atol(numbers[i]) == ft_atol(numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input_string(const char *input)
{
	char	**numbers;
	int		valid;
	int		count;

	if (!input || *input == '\0' || has_consecutive_spaces(input))
		return (0);
	numbers = ft_split(input, ' ');
	if (!numbers)
		return (0);
	valid = 1;
	count = 0;
	while (numbers[count])
	{
		if (!is_valid_number(numbers[count]))
		{
			valid = 0;
			break ;
		}
		count++;
	}
	if (valid && count > 1 && has_duplicates_in_str(numbers, count))
		valid = 0;
	free_split_args(numbers);
	return (valid);
}
