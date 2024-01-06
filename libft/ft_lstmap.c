/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:02:18 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/05/11 10:50:31 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	t_list	*newnode;
	void	*content;

	newlst = NULL;
	if (lst && f && del)
	{
		node = lst;
		while (node)
		{
			content = f(node->content);
			newnode = ft_lstnew(content);
			if (!newnode)
			{
				free(content);
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, newnode);
			node = node->next;
		}
	}
	return (newlst);
}
