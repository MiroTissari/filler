/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:27:00 by mtissari          #+#    #+#             */
/*   Updated: 2021/12/01 15:10:40 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_count(char const *s1, char cc)
{
	int		count;
	int		arr;

	arr = 0;
	count = 0;
	while (s1[count] != '\0')
	{
		while (s1[count] == cc)
			count++;
		if (s1[count] != cc && s1[count] != '\0')
		{
			while (s1[count] != cc && s1[count] != '\0')
				count++;
			arr++;
		}
	}
	return (arr);
}

static int	char_count(char const *str, char a)
{
	int		i;

	i = 0;
	while (str[i] != a && str[i] != '\0')
	{
		i++;
	}
	i = i + 1;
	return (i);
}

static char	*ft_split(char *nstr, char const *str, char c)
{
	int		x;
	int		y;

	x = 0;
	while (str[x] != '\0' && str[x] != c)
	{
		y = 0;
		while (str[x] != c && str[x] != '\0')
		{
			nstr[y] = str[x];
			y++;
			x++;
		}
		nstr[y] = '\0';
	}
	nstr[y] = '\0';
	return (nstr);
}

static char	**make_newstr(char const *s, char c)
{
	int		x;
	char	**newstring;

	if (!s)
		return (NULL);
	x = arr_count (s, c);
	newstring = (char **)malloc(sizeof(char *) * (x + 1));
	if (newstring == NULL)
		return (NULL);
	newstring[x] = NULL;
	return (newstring);
}

char	**ft_strsplit(char const *s, char c)
{
	int		x;
	int		z;
	char	**newstr;

	newstr = make_newstr (s, c);
	if (newstr == NULL)
		return (NULL);
	x = 0;
	z = -1;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0' && s[x] != c)
		{
			newstr[++z] = (char *)malloc (sizeof(char) * char_count (&s[x], c));
			if (newstr[z] == NULL)
				return (ft_2d_free(newstr));
			newstr[z] = ft_split (newstr[z], &s[x], c);
		}
		while (s[x] != c && s[x] != '\0')
			x++;
	}
	return (newstr);
}
