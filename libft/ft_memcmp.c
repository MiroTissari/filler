/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:33:50 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/23 15:15:37 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n && (s1 || s2))
	{
		if (((unsigned char *)s1)[x] != ((unsigned char *)s2)[x])
			return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
		x++;
	}
	return (0);
}
