/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:26:09 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/11 18:40:37 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;
	size_t	i;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	x = dstsize - ft_strlen(dst) - (sizeof(char) * 1);
	y = 0;
	i = 0;
	while (dst[i])
		i++;
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (y < x && src[y] != '\0')
	{
		dst[i + y] = src[y];
		y++;
	}
	dst[i + y] = '\0';
	return (len);
}
