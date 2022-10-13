/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:56:50 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/13 15:25:10 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	print_coords(t_filler *data, t_piece *piece)
{
	if (piece->found == 0)
	{
		reset_data(data, piece);
		return (END);
	}
	ft_putnbr(data->best_y);
	ft_putchar(' ');
	ft_putnbr(data->best_x);
	ft_putchar('\n');
	return (reset_data(data, piece));
}

void	save_value(t_filler *data, t_piece *piece, int i, int j)
{
	piece->found = 1;
	if (piece->temp_value < data->best_val)
	{
		data->best_val = piece->temp_value;
		data->best_y = i;
		data->best_x = j;
	}
	else if (piece->temp_value == data->best_val
		&& data->boss_sign == 'O')
	{
		data->best_val = piece->temp_value;
		data->best_y = i;
		data->best_x = j;
	}
}

int	check_overlay(t_filler *data, t_piece *piece, int i, int j)
{
	piece->temp_value += data->map[i][j];
	if (data->map[i][j] == data->boss)
		return (1);
	else if (data->map[i][j] == data->enemy)
		return (100);
	else
		return (0);
}

void	fit_in_piece(t_filler *data, t_piece *piece, int i, int j)
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
			if (piece->piece[ii][jj] == -3)
			{
				overlay += check_overlay(data, piece, i + ii, j + jj);
			}
			jj++;
		}
		ii++;
	}
	if (overlay == 1)
		save_value(data, piece, i, j);
	piece->temp_value = 0;
}

int	get_coords(t_filler *data, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->mapsize_y - data->piece_y)
	{
		j = 0;
		while (j <= data->mapsize_x - data->piece_x)
		{
			fit_in_piece(data, piece, i, j);
			j++;
		}
		i++;
	}
	return (print_coords(data, piece));
}

/*
	Here we go once through the heat map fitting the piece in every cell.
	The best coordinates get saved in the struct
	and then printed on standard output.
	If there is no cell the piece fits in, we print 0 0 and that ends the game
	for us.
*/
