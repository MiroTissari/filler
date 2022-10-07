/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:14:21 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/08 16:34:06 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfree(t_list **alst)
{
	t_list	*temp;

	if (!alst || !*alst)
		return (NULL);
	while ((*alst))
	{
		temp = *alst;
		temp->content = NULL;
		temp->content_size = 0;
		free (temp);
		*alst = (*alst)->next;
		temp->next = NULL;
	}
	alst = NULL;
	return (alst);
}
