/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_data_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:30 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 16:12:38 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"

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
	printf("\n");
	while (line[j] != '\0' && j < data->piece_x)
	{
		if (line[j] == '.')
			piece->piece[i][j] = 0;
		else if (line[j] == '*')
		{
			piece->piece[i][j] = -3;
		}
		printf("%i ", piece->piece[i][j]);
		j++;
	}
	printf("\n");
}

int	read_piece(t_filler *data, t_piece *piece)
{
	int	i;
	int	ret;

	i = 0;
	printf("reading piece \n");
	ret = get_next_line(data->fd, &data->line);
	convert_to_int_piece(data, data->line, piece, i);
	ft_strdel(&data->line);
	printf("piece[%i] has been read\n", i);
	i++;
	while (i < data->piece_y && ret == 1)
	{
		printf("\t\ti = %i", i);
		ret = get_next_line(data->fd, &data->line);
		if (ret != 1)
			return (ret);
		convert_to_int_piece(data, data->line, piece, i);
		ft_strdel(&data->line);
		i++;
	}
	return (1);
}

int	get_piece(t_filler *data)
{
	t_piece	*piece;

	printf("\t\tget piece\n");
	data->piece_y = ft_atoi(ft_strchr(data->line, ' ') + 1);
	data->piece_x = ft_atoi(ft_strrchr(data->line, ' ') + 1);
	piece = (t_piece *)malloc(sizeof(t_piece));
	data->piece = piece;
	ft_strdel(&data->line);
	if (!init_piece(data, piece))
		return (0);
	if (!read_piece(data, piece))
		return (0);
	return (1);
}
