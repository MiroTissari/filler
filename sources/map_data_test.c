
#include "filler.h"

int	check_columns(t_filler *data, int fd)
{
	int	i;
	int	ret;

	i = 0;
	ret = get_next_line(fd, &data->line);
	if (ret < 0)
		return (0);
	while (data->line[i] == ' ')
		i++;
	while (ft_isdigit(data->line[i]))
		i++;
	printf("column line:%s\n", data->line);
	//ft_strdel(&data->line);
	if (i != data->mapsize_x + 4)
		return (0);
	return (ret);
}

int	check_map_size(t_filler *data, int fd)
{
	int	i;
	int	j;
	int	ret;

	printf("checking map size:\n");
	ret = get_next_line(fd, &data->line);
	//if (ret == 0)
	//	data->ret = 0;
	//	return(0);
	printf("ret: %i\n", ret);
	if (ret < 0)
		return (0);
	printf("line: %s\n", data->line);
	if (ft_strncmp(data->line, "Plateau", 7))//strncmp & 7
		return (0);
	i = ft_strchr_place(data->line, ' ') + 1;
	j = ft_strrchr_place(data->line, ' ') + 1;
	if (data->mapsize_y == 0 && data->mapsize_x == 0)
	{
		data->mapsize_y = ft_atoi(&data->line[i]);
		data->mapsize_x = ft_atoi(&data->line[j]);
	}
	if (ft_atoi(&data->line[i]) != data->mapsize_y
		|| ft_atoi(&data->line[j]) != data->mapsize_x)
		return (0);
	//ft_strdel(&data->line);
	if (!check_columns(data, fd))
		return (0);
	printf("map size y: %i\n", data->mapsize_y);
	printf("map size x: %i\n", data->mapsize_x);
	return (ret);
}

void	convert_to_int_map(t_filler *data, char *line, int i, int j)
{
	int	x;

	x = 0;
	while (line[j] != '\0')
	{
		if (line[j] == '.')
			data->map[i][x] = 0;
		else if (line[j] == data->boss_sign || line[j] == data->boss_sign_s)
			data->map[i][x] = -1;
		else if (line[j] == data->enemy_sign || line[j] == data->enemy_sign_s)
			data->map[i][x] = -2;
		printf("%i", data->map[i][x]);
		j++;
		x++;
	}
	printf("\n");
}

int	read_map(t_filler *data, int fd)
{
	int	i;
	int	j;
	int	ret;
	//char	*temp;

	i = 0;
	while(i < data->mapsize_y)
	{
		ret = get_next_line(fd, &data->line);
		//temp = data->line;
		if (ret < 0)
			return (0);
		j = ft_strchr_place(data->line, ' ') + 1;
		convert_to_int_map(data, data->line, i, j);
		//ft_strdel(&data->line);
		i++;
	}
	data->map[i] = NULL;
	return (ret);
}

int	get_map_and_piece(t_filler *data, int fd)
{
	t_piece	*piece;
	int		ret;

	ret = 1;
	printf("get_map_and_piece1\n");
	if (data->first_round == 0)
		ret = check_map_size(data, fd);
	printf("get_map_and_piece2\n");
	if (ret != 1 || read_map(data, fd) != 1)
		return (0);
	printf("get_map_and_piece3\n");
	if (!read_piece_size(data, fd))
		return (0);
	printf("get_map_and_piece4\n");
	piece = (t_piece *)malloc(sizeof(t_piece));
	printf("get_map_and_piece5\n");
	if (!read_piece(data, piece, fd))
		return (0);
	printf("get_map_and_piece6\n");
	data->piece = piece;
	return (ret);
}
