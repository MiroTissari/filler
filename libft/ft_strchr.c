/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:49:05 by mtissari          #+#    #+#             */
/*   Updated: 2022/02/08 16:31:05 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	cc;

	cc = c;
	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
	{
		if (s[x] == cc)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == '\0' && s[x] == cc)
		return ((char *)&s[x]);
	return (0);
}
