/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 19:16:33 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	sorter(t_filler *data, int ret)
{
	t_piece	*piece;

	if (ret != 1)
		return (0);
	if (!ft_strncmp(data->line, "$$$ exec", 8))
		return (get_players(data));
	else if (!ft_strncmp(data->line, "Plateau", 7))
	{
		if (!get_map(data))
			return (0);
		create_heat_map(data);
	}
	else if (!ft_strncmp(data->line, "Piece", 5))
	{
		piece = (t_piece *)malloc(sizeof(t_piece));
		if (!piece)
			return (0);
		if (!get_piece(data, piece))
			return (0);
		if (!get_coords(data, piece))
			return (0);
	}
	return (1);
}

int	main(void)
{
	t_filler	data;
	int			ret;

	ret = 1;
	init_t_filler(&data);
	while (get_next_line(0, &data.line))
	{
		if (!sorter(&data, ret))
			return (free_all(&data, ret));
	}
	return (free_all(&data, ret));
}
