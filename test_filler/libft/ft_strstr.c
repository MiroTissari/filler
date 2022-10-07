/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:35:13 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/24 13:38:03 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	x;

	x = 0;
	if (needle[x] == '\0')
		return ((char *)&haystack[x]);
	while (haystack[x] != '\0')
	{
		if (ft_strncmp (&haystack[x], needle, ft_strlen (needle)) == 0)
			return ((char *)&haystack[x]);
		x++;
	}
	return (0);
}
