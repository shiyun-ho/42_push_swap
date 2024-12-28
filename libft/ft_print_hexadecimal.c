/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:24:55 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:18 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

#define MAX_HEX_DIGITS 17

void	convert_to_hexadecimal_uppercase(unsigned long n, char *str)
{
	unsigned long	remainder;
	int				i;

	i = 0;
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder <= 16)
		{
			if (remainder < 10)
				str[i] = remainder + '0';
			else
				str[i] = remainder - 10 + 'A';
			i++;
		}
		n = n / 16;
	}
	str[i] = '\0';
}

void	convert_to_hexadecimal_lowercase(unsigned long n, char *str)
{
	unsigned long	remainder;
	int				i;

	i = 0;
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			str[i] = remainder + '0';
		else
			str[i] = remainder - 10 + 'a';
		i++;
		n = n / 16;
	}
	str[i] = '\0';
}

static void	reverse_hexadecimal_order(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int	ft_print_hexadecimal_upper(unsigned int n)
{
	char			*hexadecimal_str;
	int				str_len;

	if (n == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	hexadecimal_str = (char *)malloc((MAX_HEX_DIGITS + 1) * sizeof(char));
	if (!hexadecimal_str)
		return (0);
	convert_to_hexadecimal_uppercase(n, hexadecimal_str);
	reverse_hexadecimal_order(hexadecimal_str);
	str_len = ft_strlen(hexadecimal_str);
	ft_putstr_fd(hexadecimal_str, 1);
	free(hexadecimal_str);
	return (str_len);
}

int	ft_print_hexadecimal_lower(unsigned int n)
{
	char			*hexadecimal_str;
	int				str_len;

	if (n == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	hexadecimal_str = (char *)malloc((MAX_HEX_DIGITS + 1) * sizeof(char));
	if (!hexadecimal_str)
		return (0);
	convert_to_hexadecimal_lowercase(n, hexadecimal_str);
	reverse_hexadecimal_order(hexadecimal_str);
	str_len = ft_strlen(hexadecimal_str);
	ft_putstr_fd(hexadecimal_str, 1);
	free(hexadecimal_str);
	return (str_len);
}
