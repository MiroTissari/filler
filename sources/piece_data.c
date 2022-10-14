/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/14 18:34:21 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	convert_to_int_piece(t_filler *data, char *line, t_piece *piece, int i)
{
	int	j;

	j = 0;
	while (j < data->piece_x)
	{
		if (line[j] == '.')
			piece->piece[i][j] = 0;
		else if (line[j] == '*')
		{
			piece->piece[i][j] = -3;
		}
		else
			data->error = 1;
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
			return (END);
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
	if (data->piece_x >= data->mapsize_x || data->piece_y >= data->mapsize_y)
		return (error_handling(data, BAD_PIECE));
	if (!init_piece(data, piece))
	{
		reset_data(data, piece);
		return (error_handling(data, BAD_MALLOC));
	}
	if (!read_piece(data, piece) || data->error == 1)
	{
		reset_data(data, piece);
		return (error_handling(data, BAD_PIECE));
	}
	return (1);
}

/*
	We make each round a new piece and convert it straight away to ints,
	where 0 stands for an empty space, or '.',
	and -3 stands '*', which means its part of the actual shape of the piece.
*/
