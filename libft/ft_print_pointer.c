/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:06:50 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:26 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

#define MAX_HEX_DIGITS 17

void	convert_to_hexadecimal_pointer(uintptr_t n, char *str)
{
	uintptr_t	remainder;
	int			i;

	i = 0;
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder <= 16)
		{
			if (remainder < 10)
				str[i] = remainder + '0';
			else
				str[i] = remainder - 10 + 'a';
			i++;
		}
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

int	ft_print_hexadecimal_pointer(uintptr_t pointer)
{
	char	*memory_address;
	int		str_len;

	memory_address = (char *)malloc((MAX_HEX_DIGITS + 1) * sizeof(char));
	if (!memory_address)
		return (-1);
	convert_to_hexadecimal_pointer(pointer, memory_address);
	reverse_hexadecimal_order(memory_address);
	str_len = ft_strlen(memory_address);
	ft_putstr_fd(memory_address, 1);
	free(memory_address);
	return (str_len);
}

int	ft_print_pointer(void *pointer)
{
	uintptr_t	memory_address;
	int			str_len;

	memory_address = (uintptr_t) pointer;
	if (memory_address == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	str_len = 2;
	str_len += ft_print_hexadecimal_pointer(memory_address);
	return (str_len);
}
