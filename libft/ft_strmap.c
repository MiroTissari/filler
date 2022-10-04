/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:56:33 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 19:31:38 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		x;

	if (!s)
		return (NULL);
	x = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s[x] != '\0')
	{
		newstr[x] = f(((char *)s)[x]);
		x++;
	}
	newstr[x] = '\0';
	return (newstr);
}
