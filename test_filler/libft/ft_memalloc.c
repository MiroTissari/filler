/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:34:43 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/18 13:50:41 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	new_mem = (void *)malloc(size);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero (new_mem, size);
	return (new_mem);
}
