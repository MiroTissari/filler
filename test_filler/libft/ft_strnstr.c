/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:59:37 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 16:59:40 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *han_lenstack, const char *needle, size_t len)
{
	size_t	x;
	size_t	n_len;

	x = 0;
	n_len = ft_strlen(needle);
	if (needle[x] == '\0')
		return ((char *)&han_lenstack[x]);
	if (ft_strlen (han_lenstack) < n_len)
		return (NULL);
	while (x + n_len <= len && han_lenstack[x] != '\0')
	{
		if (ft_strncmp(&han_lenstack[x], needle, n_len) == 0)
			return ((char *)&han_lenstack[x]);
		x++;
	}
	return (0);
}
