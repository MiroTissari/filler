/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 19:44:32 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_header/filter.h"

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
	else if (!ft_strncmp(data->line, "Piece", 5))
	{
		if (!get_piece(data))
			return (0);
		printf("\tpiece size y: %i\n", data->piece_y);
		printf("\tpiece size x: %i\n", data->piece_x);
		if (!get_coords(data))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_filler	data;
	int			ret;
	int			fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	data.fd = fd;
	init_t_filler(&data);
	while (ret)
	{
		ret = get_next_line(fd, &data.line);
		printf("line: %s\n", data.line);
		if (!sorter(&data, ret))
			return (free_all(&data, ret));
		//ft_strdel(&data.line);
		system("leaks test_file");
	}
	return (free_all(&data, ret));
}
