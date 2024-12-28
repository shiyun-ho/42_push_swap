/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:37:00 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:40 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printnbr(int value)
{
	char		*int_to_str;
	int			str_len;

	int_to_str = ft_itoa(value);
	str_len = ft_strlen(int_to_str);
	ft_putstr_fd(int_to_str, 1);
	free(int_to_str);
	return (str_len);
}
