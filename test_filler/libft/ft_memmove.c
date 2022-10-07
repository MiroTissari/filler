/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:37:38 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/01 15:30:35 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	x;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		x = len - 1;
		while (x >= 0)
		{
			((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
			x--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
