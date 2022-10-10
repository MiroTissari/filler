/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 20:02:31 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_piece(t_filler *data, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	piece->piece = (int **)malloc(sizeof(int *) * data->piece_y);
	if (!piece->piece)
		return (0);
	while (i < data->piece_y)
	{
		piece->piece[i] = (int *)malloc(sizeof(int) * data->piece_x);
		if (!piece->piece[i])
			return (0);
		j = 0;
		while (j < data->piece_x)
		{
			piece->piece[i][j] = 0;
			j++;
		}
		i++;
	}
	piece->found = 0;
	piece->temp_value = 0;
	return (1);
}

void	convert_to_int_piece(t_filler *data, char *line, t_piece *piece, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\0' && j < data->piece_x)
	{
		if (line[j] == '.')
			piece->piece[i][j] = 0;
		else if (line[j] == '*')
		{
			piece->piece[i][j] = -3;
		}
		j++;
	}
}

int	read_piece(t_filler *data, t_piece *piece)
{
	int	i;
	int	ret;

	i = 0;
	while (i < data->piece_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret != 1)
			return (0);
		convert_to_int_piece(data, data->line, piece, i);
		ft_strdel(&data->line);
		i++;
	}
	return (1);
}

int	get_piece(t_filler *data, t_piece *piece)
{
	data->piece_y = ft_atoi(ft_strchr(data->line, ' ') + 1);
	data->piece_x = ft_atoi(ft_strrchr(data->line, ' ') + 1);
	ft_strdel(&data->line);
	if (!init_piece(data, piece))
	{
		reset_data(data, piece);
		return (0);
	}
	if (!read_piece(data, piece))
	{
		reset_data(data, piece);
		return (0);
	}
	return (1);
}
