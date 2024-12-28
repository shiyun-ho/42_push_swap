/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:54:11 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:44 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	int		i;
	int		strlen;

	i = 0;
	strlen = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		strlen += 6;
		return (strlen);
	}
	strlen = (int) ft_strlen(s);
	while (i < strlen)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (strlen);
}
