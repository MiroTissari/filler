/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 14:57:32 by mtissari         ###   ########.fr       */
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

int	read_piece(t_filler *data, t_piece *piece, int ret)
{
	int	i;

	i = 0;
	if (!init_piece(data, piece))
		return (0);
	while (i < data->piece_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret != 1)
			return (ret);
		convert_to_int_piece(data, data->line, piece, i);
		ft_strdel(&data->line);
		i++;
	}
	return (ret);
}

int	read_piece_size(t_filler *data, int ret)
{
	int	i;
	int	j;

	ret = get_next_line(0, &data->line);
	if (ret != 1)
		return (ret);
	if (!ft_strncmp(data->line, "Piece", 5))
		return (0);
	i = ft_strchr_place(data->line, ' ') + 1;
	j = ft_strrchr_place(data->line, ' ') + 1;
	data->piece_y = ft_atoi(&data->line[i]);
	data->piece_x = ft_atoi(&data->line[j]);
	ft_strdel(&data->line);
	return (ret);
}
