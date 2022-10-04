/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:06:10 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/01 15:08:07 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		x;
	int		y;
	int		z;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	y = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	while ((s[y] == ' ' || s[y] == '\n' || s[y] == '\t') && y >= x)
		y--;
	str = (char *)malloc(sizeof(char) * (y - x + 2));
	if (str == NULL)
		return (NULL);
	z = 0;
	while (x <= y)
	{
		str[z] = s[x];
		z++;
		x++;
	}
	str[z] = '\0';
	return (str);
}
