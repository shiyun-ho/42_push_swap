/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exception.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:15:57 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:06 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_exception(char c)
{
	int	strlen;

	if (c != '\0')
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		strlen = 2;
	}
	else
		strlen = -1;
	return (strlen);
}
