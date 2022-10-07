/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:41:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 16:41:32 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	double_power(long double num, int prec)
{
	long double	i;
	int			j;

	j = 0;
	i = 1.0;
	while (j < prec)
	{
		i *= num;
		j++;
	}
	return (i);
}
