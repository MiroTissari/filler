
#include "filler.h"

int	check_columns(t_filler *data, int ret)
{
	int	i;

	i = 0;
	ret = get_next_line(0, &data->line);
	if (ret < 0)
		return (0);
	while (data->line[i] == ' ')
		i++;
	while (ft_isdigit(data->line[i]))
		i++;
	ft_strdel(&data->line);
	if (i != data->mapsize_x + 4)
		return (0);
	return (ret);
}

int	check_map_size(t_filler *data, int ret)
{
	int	i;
	int	j;

	ret = get_next_line(0, &data->line);
	if (ret < 0)
		return (0);
	if (ft_strnstr(data->line, "Plateau", 8))
		return (0);
	i = ft_strchr(data->line, ' ') + 1;
	j = ft_strrchr(data->line, ' ') + 1;
	if (data->mapsize_y == 0 && data->mapsize_x == 0)
	{
		data->mapsize_y = ft_atoi(&data->line[i]);
		data->mapsize_x = ft_atoi(&data->line[j]);
		data->map = (char **)malloc(sizeof(char *) * data->mapsize_y);
		if (!data->map)
			return (0);
	}
	if (ft_atoi(&data->line[i]) != data->mapsize_y ||
		ft_atoi(&data->line[j]) != data->mapsize_x)
		return (0);
	ft_strdel(&data->line);
	if (!check_columns(data, ret))
		return (0);
	return (ret);
}

void	convert_to_int_map(t_filler *data, char *line, int i, int j)
{
	int	x;

	while (line[j] != '0')
	{
		if (line[j] == '.')
			data->map[i][x] = 0;
		else if (line[j] == data->boss_sign || line[j] == data->boss_sign_s)
			data->map[i][x] = -1;
		else if (line[j] == data->enemy_sign || line[j] == data->enemy_sign_s)
			data->map[i][x] = -2;
		i++;
		j++;
	}
}

int	read_map(t_filler *data, int ret)
{
	int	i;
	int	j;

	i = 0;
	while(i < data->mapsize_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret < 0)
			return (0);
		j = ft_strchr(data->line, ' ');
		convert_to_int_map(data, data->line, i, j);
		ft_strdel(&data->line);
	}
	data->map[i] = NULL;
	return (ret);
}

int	get_map_and_piece(t_filler *data, int ret)
{
	t_piece	*piece;

	if (data->first_round == 0)
		ret = !check_map_size(data, ret);
	if (ret != 1 || !read_map(data, ret))
		return (0);
	if (!read_piece_size(data, ret))
		return (0);
	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!read_piece(data, piece, ret))
		return (0);
	data->piece = piece;
	return (ret);
}
