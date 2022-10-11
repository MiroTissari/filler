/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:01 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/11 17:10:10 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"

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

void	set_heat_value(t_filler *data, int i, int j)
{
	if (data->target == -2)
	{
		if (data->map[i][j + 1] == 0)
			data->map[i][j + 1] = 1;
		if (data->map[i][j - 1] == 0)
			data->map[i][j - 1] = 1;
		if (data->map[i + 1][j] == 0)
			data->map[i + 1][j] = 1;
		if (data->map[i - 1][j] == 0)
			data->map[i - 1][j] = 1;
		return ;
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
				set_heat_value(data, i, j);
				data->target_found = 1;
			}
			j++;
		}
		i++;
	}
	if (data->target == -2)
		data->target = 0;
	data->target++;
	if (data->target_found == 1)
		create_heat_map(data);
	check_for_empties(data);
}
