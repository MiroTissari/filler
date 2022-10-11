/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:01 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/11 18:16:19 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_for_empties(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapsize_y)
	{
		j = 0;
		while (j < data->mapsize_x)
		{
			if (data->map[i][j] == 0)
			{
				data->map[i][j] = 100;
			}
			j++;
		}
		i++;
	}
}

int	set_heat_value(t_filler *data, int i, int j)
{
	if (data->target == data->enemy)
	{
		if ((j + 1) < data->mapsize_x && data->map[i][j + 1] == 0)
			data->map[i][j + 1] = 1;
		if ((j - 1) >= 0 && data->map[i][j - 1] == 0)
			data->map[i][j - 1] = 1;
		if ((i + 1) < data->mapsize_y && data->map[i + 1][j] == 0)
			data->map[i + 1][j] = 1;
		if ((i - 1) >= 0 && data->map[i - 1][j] == 0)
			data->map[i - 1][j] = 1;
		return (1);
	}
	if ((j + 1) < data->mapsize_x && (data->map[i][j + 1] == 0
		|| data->map[i][j + 1] > data->map[i][j] + 1))
		data->map[i][j + 1] = data->map[i][j] + 1;
	if ((j - 1) >= 0 && (data->map[i][j - 1] == 0
		|| data->map[i][j - 1] > data->map[i][j] + 1))
		data->map[i][j - 1] = data->map[i][j] + 1;
	if ((i + 1) < data->mapsize_y && (data->map[i + 1][j] == 0
		||data->map[i + 1][j] > data->map[i][j] + 1))
		data->map[i + 1][j] = data->map[i][j] + 1;
	if ((i - 1) >= 0 && (data->map[i - 1][j] == 0
		|| data->map[i - 1][j] > data->map[i][j] + 1))
		data->map[i - 1][j] = data->map[i][j] + 1;
	return (1);
}

void	create_heat_map(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
	data->target_found = 0;
	while (i < data->mapsize_y)
	{
		j = 0;
		while (j < data->mapsize_x)
		{
			if (data->map[i][j] == data->target)
			{
				data->target_found = set_heat_value(data, i, j);
			}
			j++;
		}
		i++;
	}
	if (data->target == data->enemy)
		data->target = 0;
	data->target++;
	if (data->target_found == 1)
		create_heat_map(data);
	check_for_empties(data);
}

/*
	The heat map is how the solver(coordinates functions) finds the best place
	for the piece.
	We go around the initial map and give each empty place a heat value.
	In case the acces to some area is blocked by my own signs(boss), we give
	them a weaker heat value.
*/
