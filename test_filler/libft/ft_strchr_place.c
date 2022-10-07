/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:05:21 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 19:05:23 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_place(const char *s, int c)
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
			return (x);
		x++;
	}
	if (s[x] == '\0' && s[x] == cc)
		return (x);
	return (0);
}
