
#include "filler.h"

int	get_players(t_filler *data, int ret)
{
	int		i;
	char	**temp; //make into ft_strchr

	i = 0;
	ret = get_next_line(0, &data->line);
	if (ret < 1)
		return (0);
	temp = ft_strsplit(data->line, ' ');
	free (data->line);
	while (!ft_strcmp(temp[i], "$$$") || !ft_strcmp(temp[i], "exec"))
		i++;
	if (!ft_strcmp(temp[i], "p1"))
	{
		data->boss_sign = 'O';
		data->enemy_sign = 'X';
	}
	else if (!ft_strcmp(temp[i], "p2"))
	{
		data->boss_sign = 'X';
		data->enemy_sign = 'O'; 
	}
	//else
	//	something has gone wrong;
	data->boss = -1;
	data->enemy = -2;
	ft_2d_free(temp);
	return (ret);
}
