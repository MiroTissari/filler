/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:01 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 17:25:42 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	int	target_found;

	i = 0;
	target_found = 0;
	while (i < data->mapsize_y)
	{
		j = 0;
		while (j < data->mapsize_x)
		{
			if (data->map[i][j] == data->target)
			{
				set_heat_value(data, i, j);
				if (data->target == -2)
					printf("value:%i\n", i);
				target_found = 1;
			}
			j++;
		}
		i++;
	}
	if (data->target == -2)
		data->target = 0;
	data->target++;
	if (target_found == 1)
		create_heat_map(data);
}
