/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:40:50 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/23 16:53:36 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	x;

	x = 0;
	while (s1[x] != '\0' || s2[x] != '\0')
	{
		if ((unsigned char)s1[x] != (unsigned char)s2[x])
			return ((unsigned char) s1[x] - (unsigned char) s2[x]);
		x++;
	}
	return (0);
}
