/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/13 14:58:20 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
			return (END);
		if (!get_piece(data, piece))
			return (END);
		if (!get_coords(data, piece))
			return (END);
	}
	return (1);
}

int	main(void)
{
	t_filler	data;

	init_t_filler(&data);
	while (get_next_line(0, &data.line))
	{
		if (!sorter(&data))
			return (free_all(&data));
	}
	return (free_all(&data));
}
