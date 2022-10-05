/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:56:50 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 17:57:16 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(t_filler *data)
{
	ft_putnbr(data->best_y);
	ft_putstr(" ");
	ft_putnbr(data->best_x);
	ft_putchar('\n');
}

void	save_value(t_filler *data, int i, int j)
{
	if (data->piece->temp_value < data->best_val)
	{
		data->best_val = data->piece->temp_value;
		data->best_y = i;
		data->best_x = j;
	}
}

int	check_overlay(t_filler *data, int i, int j)
{
	data->piece->temp_value += data->map[i][j];
	if (data->map[i][j] == data->boss)
		return (1);
	else if (data->map[i][j] == data->enemy)
		return (100);
	else
		return (0);
}

void	fit_in_piece(t_filler *data, int i, int j)
{
	int	overlay;
	int	ii;
	int	jj;

	ii = 0;
	overlay = 0;
	while (ii < data->piece_y)
	{
		jj = 0;
		while (jj < data->piece_x)
		{
			if (data->piece->piece[ii][jj] == -3)
			{
				overlay += check_overlay(data, i + ii, j + jj);
			}
			jj++;
		}
		ii++;
	}
	if (overlay == 1)
		save_value(data, i, j);
	data->piece->temp_value = 0;
}

void	get_coords(t_filler *data)
{
	int	i;
	int	j;

	i = 0;
	printf("coords\n");
	while (i <= data->mapsize_y - data->piece_y)
	{
		j = 0;
		while (j <= data->mapsize_x - data->piece_x)
		{
			fit_in_piece(data, i, j);
			j++;
		}
		i++;
	}
	printf("coords2\n");
	print_coords(data);
}
