/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:59:03 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/10 13:08:50 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	ch;
	unsigned char	*result;

	ch = c;
	x = 0;
	while (x < n)
	{
		((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
		if (((unsigned char *)src)[x] == ch)
		{
			result = &((unsigned char *)dst)[x + 1];
			return (result);
		}
		x++;
	}
	result = NULL;
	return (result);
}
