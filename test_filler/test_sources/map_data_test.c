/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:09 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 14:59:38 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"

int	make_grid(t_filler *data)
{
	int	i;
	int	j;

	printf("make grid");
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
	printf("\t grid made\n");
	return (1);
}

void	convert_to_int_map(t_filler *data, char *line, int i, int j)
{
	int	x;

	x = 0;
	printf("map in int[%i]\t\t\t\t\t", i);
	while (line[j] != '\0')
	{
		if (line[j] == '.')
			data->map[i][x] = 0;
		else if (line[j] == data->boss_sign || line[j] == data->boss_sign_s)
			data->map[i][x] = -1;
		else if (line[j] == data->enemy_sign || line[j] == data->enemy_sign_s)
			data->map[i][x] = -2;
		printf("%i ", data->map[i][x]);
		j++;
		x++;
	}
	printf("\n");
}

int	read_map(t_filler *data, int ret)
{
	int	i;
	int	j;

	i = 0;
	printf("start reading map\n");
	j = ft_strchr_place(data->line, ' ') + 1;
	convert_to_int_map(data, data->line, i, j);
	ft_strdel(&data->line);
	i++;
	while (i < data->mapsize_y)
	{
		ret = get_next_line(data->fd, &data->line);
		if (ret != 1)
			return (ret);
		j = ft_strchr_place(data->line, ' ') + 1;
		convert_to_int_map(data, data->line, i, j);
		ft_strdel(&data->line);
		i++;
	}
	return (ret);
}

int	skip_lines(t_filler *data)
{
	int	ret;

	ret = get_next_line(data->fd, &data->line);
	printf("skipping line: %s\n", data->line);
	if (ret != 1)
		return (0);
	if (!ft_strncmp(data->line, "000 ", 4))
	{
		printf("\t\t\tskip_line success!\n");
		return (1);
	}
	else
		ft_strdel(&data->line);
	skip_lines(data);
	return (0);
}

int	get_map(t_filler *data)
{
	int	ret;

	printf("\tget map\n");
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
