/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:58:31 by shiyun            #+#    #+#             */
/*   Updated: 2024/07/20 17:14:59 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* desc: Converts lowercase to uppercase
* if c == lowercase, return uppercase equivalent
* if c is not unsigned char OR EOF, behavior == UNDEFINED
* @params:
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
