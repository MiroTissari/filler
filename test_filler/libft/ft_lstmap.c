/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:44:48 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/08 17:47:16 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*tail;
	t_list	*start;

	start = NULL;
	while (lst)
	{
		temp = f (lst);
		if (!start)
		{
			start = ft_lstnew(temp->content, temp->content_size);
			tail = start;
		}
		else
		{
			tail->next = ft_lstnew(temp->content, temp->content_size);
			tail = tail->next;
			if (tail == NULL)
				return ((t_list *)ft_lstfree(&start));
		}
		lst = lst->next;
		free (temp);
	}
	return (start);
}
