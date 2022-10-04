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
#include <fcntl.h>

void	init_t_filler(t_filler *data)
{
	data->boss = -1;
	data->enemy = -2;
	data->boss_sign = 0;
	data->enemy_sign = 0;
	data->boss_sign_s = 0;
	data->enemy_sign_s = 0;
	data->map = NULL;
	data->line = NULL;
	data->mapsize_x = 0;
	data->mapsize_y = 0;

	data->target = data->enemy;
	data->first_round = 1;
	data->best_val = 500;
	data->best_x = 0;
	data->best_y = 0;

	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
	printf("initializing t_filler\n");
}

void	reset_data(t_filler *data)
{
	int	i;

	data->line = NULL;
	data->first_round = 0;
	data->target = data->enemy;
	data->best_val = 500;
	data->best_x = 0;
	data->best_y = 0;
	i = 0;
	while (data->piece->piece[i])
	{
		free (data->piece->piece[i]);
		data->piece->piece[i] = NULL;
		i++;
	}
	free(data->piece);
	data->piece->piece = NULL;
	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
	printf("reset_data\n");
}

int	make_grid(t_filler *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	printf("making grid\n");
	if (!check_map_size(data, fd))
		return (0);
	data->map = (int **)malloc(sizeof(int *) * data->mapsize_y);//this
	while (i < data->mapsize_y)
	{
		printf("\t\t\t\t");
		j = 0;
		data->map[i] = (int *)malloc(sizeof(int) * data->mapsize_x);
		while (j < data->mapsize_x)
		{
			data->map[i][j] = 0;
			printf(" %i", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	//data->map[i] = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_filler	data;
	int			ret;
	int			fd;

	ret = 1;
	if (argc == 2)
		fd = open (argv[1], O_RDONLY);
	else
		return (0);
	init_t_filler(&data);
	if (!get_players(&data, fd) || !make_grid(&data, fd))
		return (1);
	while (ret == 1)
	{
		if (!get_map_and_piece(&data, fd))
			return (1);
		create_heat_map(&data);
		get_coords(&data);
		reset_data(&data);
		close (fd);
	}
	return (0);
}
