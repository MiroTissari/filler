/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:09 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 14:57:11 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_columns(t_filler *data, int ret)
{
	int	i;

	i = 0;
	ret = get_next_line(0, &data->line);
	if (ret < 0)
		return (0);
	while (data->line[i] == ' ')
		i++;
	while (ft_isdigit(data->line[i]))
		i++;
	ft_strdel(&data->line);
	if (i != data->mapsize_x + 4)
		return (0);
	return (ret);
}

int	check_map_size(t_filler *data, int ret)
{
	int	i;
	int	j;

	ret = get_next_line(0, &data->line);
	if (ret != 1)
		return (ret);
	if (!ft_strncmp(data->line, "Plateau", 7))
		return (0);
	i = ft_strchr_place(data->line, ' ') + 1;
	j = ft_strrchr_place(data->line, ' ') + 1;
	if (data->mapsize_y == 0 && data->mapsize_x == 0)
	{
		data->mapsize_y = ft_atoi(&data->line[i]);
		data->mapsize_x = ft_atoi(&data->line[j]);
	}
	if (ft_atoi(&data->line[i]) != data->mapsize_y
		|| ft_atoi(&data->line[j]) != data->mapsize_x)
		return (0);
	ft_strdel(&data->line);
	if (!check_columns(data, ret))
		return (0);
	return (ret);
}

void	convert_to_int_map(t_filler *data, char *line, int i, int j)
{
	int	x;

	x = 0;
	while (line[j] != '0')
	{
		if (line[j] == '.')
			data->map[i][x] = 0;
		else if (line[j] == data->boss_sign || line[j] == data->boss_sign_s)
			data->map[i][x] = -1;
		else if (line[j] == data->enemy_sign || line[j] == data->enemy_sign_s)
			data->map[i][x] = -2;
		j++;
		x++;
	}
}

int	read_map(t_filler *data, int ret)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapsize_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret != 1)
			return (ret);
		j = ft_strchr_place(data->line, ' ') + 1;
		convert_to_int_map(data, data->line, i, j);
		ft_strdel(&data->line);
		i++;
	}
	return (ret);
}

int	get_map_and_piece(t_filler *data, int ret)
{
	t_piece	*piece;

	if (data->first_round == 0)
		ret = check_map_size(data, ret);
	if (ret != 1 || !read_map(data, ret))
		return (ret);
	if (!read_piece_size(data, ret))
		return (0);
	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!read_piece(data, piece, ret))
		return (0);
	data->piece = piece;
	return (ret);
}
