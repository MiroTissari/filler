
#include "filler.h"

int	get_players(t_filler *data, int fd)
{
	char	**temp;
	int		ret;

	printf("player_data:\n");
	ret = get_next_line(fd, &data->line);
	if (ret < 1)
		return (0);
	temp = ft_strsplit(data->line, ' ');
	//ft_strdel (&data->line);
	if (ft_strcmp(temp[0], "$$$") || ft_strcmp(temp[1], "exec"))
		return (0);
	if (!ft_strcmp(temp[2], "p1"))
	{
		data->boss_sign = 'O';
		data->enemy_sign = 'X';
	}
	else if (!ft_strcmp(temp[2], "p2"))
	{
		data->boss_sign = 'X';
		data->enemy_sign = 'O'; 
	}
	else
		return (0);
	printf("\tboss_sign: %c\n", data->boss_sign);
	printf("\tenemy_sign: %c\n", data->enemy_sign);
	ft_2d_free(temp);
	printf("checkkk\n");
	return (ret);
}
