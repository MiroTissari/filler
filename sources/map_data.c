/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:09 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/11 18:21:07 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	make_grid(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
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
	return (1);
}

void	convert_to_int_map(t_filler *data, char *line, int i, int j)
{
	int	x;

	x = 0;
	while (x < data->mapsize_x)
	{
		if (line[j] == '.')
			data->map[i][x] = 0;
		else if (line[j] == data->boss_sign || line[j] == data->boss_sign_s)
			data->map[i][x] = data->boss;
		else if (line[j] == data->enemy_sign || line[j] == data->enemy_sign_s)
			data->map[i][x] = data->enemy;
		j++;
		x++;
	}
}

int	read_map(t_filler *data, int ret)
{
	int	i;
	int	j;

	i = 0;
	j = 4;
	convert_to_int_map(data, data->line, i, j);
	ft_strdel(&data->line);
	i++;
	while (i < data->mapsize_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret != 1)
			return (ret);
		convert_to_int_map(data, data->line, i, j);
		ft_strdel(&data->line);
		i++;
	}
	return (ret);
}

int	skip_lines(t_filler *data)
{
	int	ret;

	ret = get_next_line(0, &data->line);
	if (ret != 1)
		return (0);
	if (!ft_strncmp(data->line, "000 ", 4))
		return (1);
	else
		ft_strdel(&data->line);
	skip_lines(data);
	return (0);
}

int	get_map(t_filler *data)
{
	int	ret;

	ret = 1;
	if (data->mapsize_y == 0 && data->mapsize_x == 0)
	{
		data->mapsize_y = ft_atoi(ft_strchr(data->line, ' ') + 1);
		data->mapsize_x = ft_atoi(ft_strrchr(data->line, ' ') + 1);
		ret = make_grid(data);
	}
	ft_strdel(&data->line);
	if (ret != 1 || skip_lines(data))
		return (0);
	ret = read_map(data, ret);
	return (ret);
}

/*
	The Grid gets made just once and we use that until the end of the program.
	We use skip_lines function to find the starting point of the map,
	which we then convert to the grid while reading it.
*/
