
#include "filler.h"

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
	data->best_val = 1000000;
	data->best_x = 0;
	data->best_y = 0;

	data->piece = NULL;
	data->piece_x = 0;
	data->piece_y = 0;
}

int	reset_data(t_filler *data)
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
		data->piece = NULL;
	}
	data->piece_x = 0;
	data->piece_y = 0;
	return (1);
}

int	free_all(t_filler *data, int ret)
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
	if (ret == 0)
		return (0);
	return (1);
}
