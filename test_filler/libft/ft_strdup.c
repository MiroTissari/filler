/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:09:02 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 16:53:01 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	x = 0;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		dest[x] = s1[x];
		x++;
	}
	dest[i] = '\0';
	return (dest);
}	
