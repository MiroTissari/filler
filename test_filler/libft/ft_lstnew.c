/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:57:39 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/02 15:45:54 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;	

	newlink = (t_list *)malloc(sizeof(t_list));
	if (newlink == NULL)
		return (NULL);
	if (content)
	{
		newlink->content = (void *)malloc(content_size);
		if (newlink->content == NULL)
		{
			free (newlink);
			return (NULL);
		}
		ft_memcpy (newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	else
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}	
	newlink->next = NULL;
	return (newlink);
}
