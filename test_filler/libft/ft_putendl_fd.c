/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:24:47 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/01 15:06:16 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	x;

	x = 0;
	if (!s)
		return ;
	while (s[x] != '\0')
	{
		ft_putchar_fd (s[x], fd);
		x++;
	}
	ft_putchar_fd ('\n', fd);
}
