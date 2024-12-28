/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:51:34 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 21:39:38 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	check_format_specifier(char param, va_list args)
{
	int	print_strlen;

	print_strlen = 0;
	if (param == 'c')
		print_strlen += ft_printchar(va_arg(args, int));
	else if (param == 's')
		print_strlen += ft_printstr(va_arg(args, char *));
	else if (param == 'd' || param == 'i')
		print_strlen += ft_printnbr(va_arg(args, int));
	else if (param == 'u')
		print_strlen += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (param == 'X')
		print_strlen += ft_print_hexadecimal_upper(va_arg(args, unsigned int));
	else if (param == 'x')
		print_strlen += ft_print_hexadecimal_lower(va_arg(args, unsigned int));
	else if (param == 'p')
		print_strlen += ft_print_pointer(va_arg(args, void *));
	else if (param == '%')
		print_strlen += ft_print_percent();
	else if (param == ' ')
		print_strlen += ft_print_no_specifier();
	else
		print_strlen += ft_print_exception(param);
	return (print_strlen);
}
/**
 * @brief Print ARGUMENT(s) according to FORMAT
 * @param {const char*} input: Takes in str
 * @param {...} variadic arg: Signals to take in variadic arguments
 * @returns {count} number of characters printed
 */

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	int				print_strlen;

	va_start(args, input);
	i = 0;
	print_strlen = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i] == '%' && input[i + 1] == '%'
				&& input[i + 2] == '\0')
				print_strlen = -1;
			print_strlen += check_format_specifier(input[i], args);
		}
		else
			print_strlen += ft_printchar((char)input[i]);
		if (input[i])
			i++;
	}
	va_end(args);
	return (print_strlen);
}
