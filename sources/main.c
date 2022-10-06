/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:39:27 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	data->first_round = 1;
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;

	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
}

void	reset_data(t_filler *data)
{
	int	i;

	data->line = NULL;
	data->first_round = 0;
	data->target = data->enemy;
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;
	if (data->piece)
	{
		i = 0;
		while (data->piece->piece[i] && i < data->piece_y)
		{
			free (data->piece->piece[i]);
			data->piece->piece[i] = NULL;
			i++;
		}
		if (data->piece->piece)
			free (data->piece->piece);
		free(data->piece);
	}
	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
}

int	free_all(t_filler *data, int ret)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->mapsize_y && data->map[i])
		{
			free (data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
	}
	if (ret == 0)
		return (0);
	return (1);
}

int	make_grid(t_filler *data, int ret)
{
	int	i;
	int	j;

	i = 0;
	if (!check_map_size(data, ret))
		return (0);
	data->map = (int **)malloc(sizeof(int *) * data->mapsize_y);
	if (!data->map)
		return (0);
	while (i < data->mapsize_y)
	{
		j = 0;
		data->map[i] = (int *)malloc(sizeof(int) * data->mapsize_x);
		if (!data->map[i])
			return (0);
		while (j < data->mapsize_x)
		{
			data->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ret);
}

int	main(void)
{
	t_filler	data;
	int			ret;

	ret = 1;
	init_t_filler(&data);
	if (!get_players(&data, ret) || !make_grid(&data, ret))
		return (1);
	while (ret == 1)
	{
		ret = get_map_and_piece(&data, ret);
		if (ret != 1)
			return (free_all(&data, ret));
		create_heat_map(&data);
		if (!get_coords(&data))
			return (free_all(&data, 0));
		reset_data(&data);
	}
	return (free_all(&data, ret));
}
