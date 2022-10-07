/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:40:45 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 17:31:24 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	count;

	count = 0;
	if (src[count] == '\0')
	{
		while (count < len)
		{
			dest[count] = '\0';
			count++;
		}
	}
	while (count < len && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	if (count < len && src[count] == '\0')
		ft_strncpy (&dest[count], &src[count], (len - count));
	return (dest);
}
