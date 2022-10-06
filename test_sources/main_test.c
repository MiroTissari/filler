/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:39:26 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 18:01:00 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
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
	data->ret = 1;

	data->target = data->enemy;
	data->first_round = 1;
	data->best_val = 1000000;
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
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;
	if (data->piece)
	{
		i = 0;
		while (data->piece->piece[i] && i < data->piece_y)
		{
			free (data->piece->piece[i]);
			data->piece->piece[i] = NULL;
			i++;
		}
		if (data->piece->piece)
			free (data->piece->piece);
		free(data->piece);
	}
	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
	printf("reset data\n");
}

int	free_all(t_filler *data, int ret, int fd)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->mapsize_y && data->map[i])
		{
			free (data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
	}
	close (fd);
	printf("\n RET: %i\n", ret);
	if (ret == 0)
		return (0);
	return (1);
}

int	make_grid(t_filler *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	printf("making grid\n");
	if (!check_map_size(data, fd))
		return (0);
	data->map = (int **)malloc(sizeof(int *) * data->mapsize_y);
	if (!data->map)
		return (0);
	while (i < data->mapsize_y)
	{
		j = 0;
		data->map[i] = (int *)malloc(sizeof(int) * data->mapsize_x);
		if (!data->map[i])
			return(0);
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
	return (1);
}

int	main(int argc, char **argv)
{
	t_filler	data;
	int			fd;
	int			i;
	int			j;

	if (argc == 2)
		fd = open (argv[1], O_RDONLY);
	else
		return (0);
	init_t_filler(&data);
	if (!get_players(&data, fd) || !make_grid(&data, fd))
		return (1);
	while (data.ret == 1)
	{
		data.ret = get_map_and_piece(&data, fd);
		if (data.ret != 1)
			return (free_all(&data, data.ret, fd));
		create_heat_map(&data);
		i = 0;
		while (i < data.mapsize_y)
		{
			j = 0;
			while (j < data.mapsize_x)
			{
				printf("%i ", data.map[i][j]);
				j++;
			}
			i++;
			printf("\n");
		}
		if (!get_coords(&data))
			return (free_all(&data, 0, fd));;
		reset_data(&data);
		system("leaks test_file");
	}
	return (free_all(&data, data.ret, fd));
}
