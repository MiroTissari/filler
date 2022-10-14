/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/14 19:04:03 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	error_handling(t_filler *data, int err_nb)
{
	if (err_nb == BAD_MAP)
	{
		write (1, "invalid map\n", 13);
	}
	else if (err_nb == BAD_INPUT)
	{
		write (1, "bad input\n", 11);
	}
	else if (err_nb == BAD_PIECE)
	{
		write (1, "bad piece\n", 11);
	}
	else if (err_nb == BAD_PLAYER)
	{
		write (1, "bad player\n", 12);
	}
	else if (err_nb == BAD_MALLOC)
	{
		write (1, "malloc failed, exit the program\n", 33);
	}
	data->error = 1;
	return (0);
}

int	sorter(t_filler *data)
{
	t_piece	*piece;

	if (!ft_strncmp(data->line, "$$$ exec", 8))
		return (get_players(data));
	else if (!ft_strncmp(data->line, "Plateau", 7))
	{
		if (!get_map(data))
			return (END);
		create_heat_map(data);
	}
	else if (!ft_strncmp(data->line, "Piece", 5))
	{
		piece = (t_piece *)malloc(sizeof(t_piece));
		if (!piece)
			return (error_handling(data, BAD_MALLOC));
		if (!get_piece(data, piece))
			return (END);
		if (!get_coords(data, piece))
			return (END);
	}
	else
		return (error_handling(data, BAD_INPUT));
	return (1);
}

int	main(void)
{
	t_filler	data;

	init_t_filler(&data);
	while (get_next_line(0, &data.line) == 1)
	{
		if (!sorter(&data))
			return (free_all(&data));
	}
	error_handling(&data, BAD_INPUT);
	return (free_all(&data));
}
