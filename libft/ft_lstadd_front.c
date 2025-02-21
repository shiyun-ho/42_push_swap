/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiyun <shiyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:37:31 by shiyun            #+#    #+#             */
/*   Updated: 2024/12/28 20:42:27 by shiyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief: Adds the node 'new' at beginning of the list
 * @param: lst - address of pointer to first node/ head of a list
 * @param: new - address of a pointer to the node to be added to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}
