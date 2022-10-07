/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:31:07 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/23 16:02:53 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	while (s[x] != '\0')
	{
		if (((unsigned char *)s)[x] == c)
			y = x;
		x++;
	}
	if (s[x] == '\0' && s[x] == c)
		return ((char *)&s[x]);
	else if (s[x] == '\0' && y != -1)
		return ((char *)&s[y]);
	return (0);
}
