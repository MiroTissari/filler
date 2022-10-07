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

#include "filter.h"

int	sorter(t_filler *data, int ret)
{
	int	i;
	int	j;

	printf("sorter\n");
	if (ret != 1)
		return (0);
	if (!ft_strncmp(data->line, "$$$ exec", 8))
		return (get_players_test(data));
	else if (!ft_strncmp(data->line, "Plateau", 7))
	{
		if (!get_map(data))
			return (0);
		create_heat_map(data);
		i = 0;
		while (i < data->mapsize_y)
		{
			j = 0;
			while (j < data->mapsize_x)
			{
				printf("%i ", data->map[i][j]);
				j++;
			}
			i++;
			printf("\n");
		}
	}
	if (!ft_strncmp(data->line, "Piece", 5))
	{
		if (!get_piece(data))
			return (0);
		printf("\tpiece size y: %i\n", data->piece_y);
		printf("\tpiece size x: %i\n", data->piece_x);
		if (!get_coords(data))
			return (free_all(data, 0));
	}
	return (1);
}

int	main(void)
{
	t_filler	data;
	int			ret;
	char		*temp;

	ret = 1;
	init_t_filler(&data);
	while (ret)
	{
		ret = get_next_line(0, &data.line);
		temp = data.line;
		printf("line: %s\n", data.line);
		if (!sorter(&data, ret))
			return (free_all(&data, ret));
		ft_strdel(&temp);
	}
	return (free_all(&data, ret));
}
