/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:36:55 by shiyun            #+#    #+#             */
/*   Updated: 2025/02/15 13:40:34 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_strlen(int n)
{
	int		str_len;
	int		value;

	str_len = 0;
	value = n;
	if (value <= 0)
	{
		str_len++;
	}
	while (value != 0)
	{
		value = value / 10;
		str_len++;
	}
	return (str_len);
}

static long	calculate_value(long n)
{
	long int	value;

	value = (long int)n;
	if (n < 0)
		value = n * -1;
	return (value);
}

static char	*create_string(size_t length)
{
	char	*str;

	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			str_len;
	long int	value;
	int			i;

	str_len = calculate_strlen(n);
	value = calculate_value(n);
	str = create_string(str_len);
	if (str)
	{
		i = str_len - 1;
		while (i >= 0)
		{
			str[i] = (value % 10) + '0';
			value = value / 10;
			i--;
			if (n < 0)
				str[0] = '-';
		}
		str[str_len] = '\0';
		return (str);
	}
	return (NULL);
}
