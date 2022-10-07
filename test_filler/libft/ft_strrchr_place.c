/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:06:00 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 19:06:01 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strrchr_place(const char *s, int c)
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
		return (x);
	else if (s[x] == '\0' && y != -1)
		return (y);
	return (0);
}
