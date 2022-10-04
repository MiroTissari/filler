/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:13:29 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/01 14:46:57 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	x;
	int				y;

	x = 0;
	y = 0;
	if (!s)
		return ;
	while (s[y] != '\0')
	{
		f(x, &s[y]);
		y++;
		x++;
	}
}
