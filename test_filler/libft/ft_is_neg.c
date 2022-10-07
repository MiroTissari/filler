/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:42:32 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/29 16:42:35 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_neg(double num)
{
	long long int	*binary;
	char			neg;

	binary = (long long int *)&num;
	neg = (char)(*binary >> 63);
	if (neg == 0)
		return (0);
	return (1);
}
