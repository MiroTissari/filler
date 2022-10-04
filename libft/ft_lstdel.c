/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:59:43 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 18:02:19 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	while ((*alst))
	{
		temp = *alst;
		del (temp->content, temp->content_size);
		free (temp);
		*alst = (*alst)->next;
		temp->next = NULL;
	}
	free (*alst);
	*alst = NULL;
}
