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
 * @brief: Adds the node 'new' at back of the list
 * @param: lst - address of pointer to first node/ head of a list
 * @param: new - address of a pointer to the node to be added to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (!new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
