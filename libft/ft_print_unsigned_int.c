/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:03:38 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:47 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <limits.h>

static int	calculate_strlen(unsigned int value)
{
	int		str_len;

	str_len = 0;
	if (value == 0)
		str_len = 1;
	while (value != 0)
	{
		value = value / 10;
		str_len++;
	}
	return (str_len);
}

static char	*create_string(size_t length)
{
	char	*str;

	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

//To convert function to choose
/**
 * @param {long} value: Input value
 * @return {int} str_len: Length of printed string
 */
int	ft_print_unsigned_int(unsigned int value)
{
	int			str_len;
	char		*str;
	int			i;

	value = (unsigned int) value;
	str_len = calculate_strlen(value);
	str = create_string(str_len);
	if (str)
	{
		i = str_len - 1;
		while (i >= 0)
		{
			str[i] = (value % 10) + '0';
			value = value / 10;
			i--;
		}
		str[str_len] = '\0';
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (str_len);
}
