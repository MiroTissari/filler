/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:27:56 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/14 17:49:06 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_t_filler(t_filler *data)
{
	data->boss = -1;
	data->enemy = -2;
	data->boss_sign = 0;
	data->enemy_sign = 0;
	data->boss_sign_s = 0;
	data->enemy_sign_s = 0;
	data->map = NULL;
	data->line = NULL;
	data->mapsize_x = 0;
	data->mapsize_y = 0;
	data->target = data->enemy;
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;
	data->piece_x = 0;
	data->piece_y = 0;
	data->error = 0;
}

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

int	reset_data(t_filler *data, t_piece *piece)
{
	int	i;

	data->target = data->enemy;
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;
	if (piece)
	{
		i = 0;
		if (piece->piece)
		{
			while (i < data->piece_y)
			{
				free (piece->piece[i]);
				piece->piece[i] = NULL;
				i++;
			}
			free (piece->piece);
		}
		free(piece);
	}
	data->piece_x = 0;
	data->piece_y = 0;
	return (1);
}

int	free_all(t_filler *data)
{
	int	i;

	i = 0;
	if (data->line)
		ft_strdel(&data->line);
	if (data->map)
	{
		while (i < data->mapsize_y)
		{
			free (data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	if (data->error == 0)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	return (END);
}
