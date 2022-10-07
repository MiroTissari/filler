/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:49:44 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/08 17:40:29 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_str_to_lst(char const *s, char c)
{
	int		x;
	t_list	*start;
	t_list	*tail;
	char	**str;
	size_t	y;

	str = ft_strsplit (s, c);
	x = -1;
	while (str[++x] != NULL)
	{
		y = ft_strlen (str[x]) + 1;
		if (x == 0)
		{
			start = ft_lstnew (str[x], y);
			tail = start;
		}
		else
		{
			tail->next = ft_lstnew (str[x], y);
			tail = tail->next;
			if (tail == NULL)
				return ((t_list *)ft_lstfree(&start));
		}
	}
	return (start);
}
