
#include "filter.h"

int	get_players(t_filler *data, int fd)
{
	int		ret;

	printf("player_data:\n");
	ret = get_next_line(fd, &data->line);
	if (ret != 1)
		return (ret);
	if (ft_strncmp(data->line, "$$$", 3))
		return (0);
	if (ft_strstr(data->line, "p1"))
	{
		data->boss_sign = 'O';
		data->enemy_sign = 'X';
	}
	else if (ft_strstr(data->line, "p2"))
	{
		data->boss_sign = 'X';
		data->enemy_sign = 'O'; 
	}
	else
		return (0);
	ft_strdel (&data->line);
	printf("\tboss_sign: %c\n", data->boss_sign);
	printf("\tenemy_sign: %c\n", data->enemy_sign);
	printf("checkkk\n");
	return (ret);
}
