/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:16:59 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/10 13:09:03 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	x;
	size_t			y;

	x = c;
	y = 0;
	while (y < len)
	{
		*((unsigned char *)(b + y)) = x;
		y++;
	}
	return (b);
}
