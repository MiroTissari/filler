
#include "filler.h"

void	set_value(t_filler *data, int i, int j)
{
	if (data->target == data->enemy)
	{
		if (data->map[i][j + 1] == 0)
			data->map[i][j + 1] = 1;
		if (data->map[i][j - 1] == 0)
			data->map[i][j - 1] = 1;
		if (data->map[i + 1][j] == 0)
			data->map[i + 1][j] = 1;
		if (data->map[i - 1][j] == 0)
			data->map[i - 1][j] = 1;
		data->target = 0;
	}
	if (data->map[i][j + 1] == 0 || data->map[i][j + 1] > data->map[i][j] + 1)
		data->map[i][j + 1] = data->map[i][j] + 1;
	if (data->map[i][j - 1] == 0 || data->map[i][j - 1] > data->map[i][j] + 1)
		data->map[i][j - 1] = data->map[i][j] + 1;
	if (data->map[i + 1][j] == 0 || data->map[i + 1][j] > data->map[i][j] + 1)
		data->map[i + 1][j] = data->map[i][j] + 1;
	if (data->map[i - 1][j] == 0 || data->map[i - 1][j] > data->map[i][j] + 1)
		data->map[i - 1][j] = data->map[i][j] + 1;
}

void	create_heat_map(t_filler *data)
{
	int	i;
	int	j;
	int	target_found;

	i = 0;
	target_found = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == data->target)
			{
				set_value(data, i, j);
				target_found = 1;
			}
			j++;
		}
		i++;
	}
	data->target++;
	if (target_found == 1)
		create_heat_map(data);
}
