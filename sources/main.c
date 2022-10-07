/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/09/20 17:39:27 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	sorter(t_filler *data, int ret)
{
	if (ret != 1)
		return (0);
	if (!ft_strncmp(data->line, "$$$ exec", 8))
		return (get_players(data));
	if (!ft_strncmp(data->line, "Plateau", 7))
	{
		if (!get_map(data))
			return (0);
		create_heat_map(data);
	}
	if (!ft_strncmp(data->line, "Piece", 5))
	{
		if (!get_piece(data))
			return (0);
		if (!get_coords(data))
			return (free_all(data, 0));
	}
	return (1);
}

int	main(void)
{
	t_filler	data;
	int			ret;

	ret = 1;
	init_t_filler(&data);
	while (ret)
	{
		ret = get_next_line(0, &data.line);
		if (!sorter(&data, ret))
			return (free_all(&data, ret));
	}
	return (free_all(&data, ret));
}
