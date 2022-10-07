/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:04:54 by mtissari          #+#    #+#             */
/*   Updated: 2022/03/08 19:01:58 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*ptr;
	size_t	y;

	y = 0;
	x = start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL || !s)
		return (NULL);
	while (y < len && s[x] != '\0')
	{
		ptr[y] = s[x];
		y++;
		x++;
	}
	ptr[y] = '\0';
	return (ptr);
}
