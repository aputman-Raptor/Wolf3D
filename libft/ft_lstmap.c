/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 15:39:03 by aputman           #+#    #+#             */
/*   Updated: 2015/12/19 16:02:19 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*lstnext;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if ((list = ft_lstnew(temp->content, temp->content_size)))
	{
		lstnext = list;
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			if (!(lstnext->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			lstnext = lstnext->next;
			lst = lst->next;
		}
	}
	return (list);
}
