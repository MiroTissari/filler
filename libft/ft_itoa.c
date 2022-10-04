/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:40:46 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/08 18:05:58 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int i)
{
	int		j;

	j = 0;
	if (i < 0)
	{
		j++;
		i = i * (-1);
	}
	while (i > 9)
	{
		i = i / 10;
		j++;
	}
	return (j + 1);
}

static void	ft_intcpy(char *string, int nb)
{
	int		x;
	int		y;
	int		z;
	int		temp;

	x = 0;
	y = ft_intlen(nb);
	if (nb < 0)
	{
		string[x] = '-';
		nb = nb * -1;
		x++;
	}
	while ((y - x) > 0)
	{
		z = x;
		temp = nb;
		while ((temp > 9 && ((y - 1) - (z++)) > 0))
			temp = temp / 10;
		string[x] = ('0' + temp % 10);
		x++;
	}
	string[x] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648\0");
		return (str);
	}
	ft_intcpy(str, n);
	return (str);
}
