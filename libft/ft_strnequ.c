/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:42:37 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/29 19:27:29 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0 || !s1 || !s2)
		return (1);
	while (x < n && s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	if (x == n || (s1[x] == '\0' && s2[x] == '\0'))
		return (1);
	return (0);
}
