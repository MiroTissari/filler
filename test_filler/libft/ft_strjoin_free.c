/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:18:31 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:03:09 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int n, int tofree)
{
	char	*new;

	if (n == 0)
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	else
		new = ft_strnew(n);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	if (tofree == 1 || tofree == 0)
	{
		ft_strdel (&s1);
		s1 = NULL;
	}
	if (tofree == 2 || tofree == 0)
	{
		ft_strdel (&s2);
		s2 = NULL;
	}
	return (new);
}
