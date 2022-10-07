/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:07:50 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 19:32:13 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	int				y;
	char			*newstr;

	if (!s)
		return (NULL);
	x = 0;
	y = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s[y] != '\0')
	{
		newstr[y] = f(x, ((char *)s)[x]);
		y++;
		x++;
	}
	newstr[y] = '\0';
	return (newstr);
}
