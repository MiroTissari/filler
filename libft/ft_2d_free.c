/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:07:39 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/08 16:35:23 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_2d_free(char **newstr)
{
	int		x;
	char	**temp;

	if (!newstr)
		return (NULL);
	x = 0;
	temp = newstr;
	while (temp[x] != NULL)
	{
		free (temp[x]);
		temp[x] = NULL;
		x++;
	}
	free (newstr);
	newstr = NULL;
	return (newstr);
}
