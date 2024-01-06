/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:51 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:44:46 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*next;

	if (*lst)
	{
		node = *lst;
		while (node)
		{
			next = node->next;
			if (node->content && del)
				del(node->content);
			free(node);
			node = next;
		}
	}
	*lst = NULL;
}
