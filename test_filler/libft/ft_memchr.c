/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:37:53 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/08 18:47:46 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	cc;
	unsigned char	*result;

	cc = c;
	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s)[x] == cc)
		{
			result = &((unsigned char *)s)[x];
			return (result);
		}
		x++;
	}
	result = NULL;
	return (result);
}
