
#include "filler.h"

void	init_piece(t_filler *data, t_piece *piece)
{
	piece->piece = (int **)malloc(sizeof(int *) * data->piece_y);
	piece->actual_size = 0;
	piece->temp_value = 0;
}

int	*convert_to_int_piece(t_filler *data, char *line, t_piece *piece)
{
	int	i;
	int	*arr;

	i = 0;
	while (line[i] != '\0')
	{
		arr = (int *)malloc(sizeof(int) * data->piece_x);
		if (!arr)
			return (0);
		if (line[i] == '.')
			arr[i] = 0;
		else if (line[i] == '*')
		{
			arr[i] = -3;
			piece->actual_size++;
		}
		i++;
	}
	return (arr);
}

int	read_piece(t_filler *data, t_piece *piece, int ret)
{
	int	i;

	i = 0;
	init_piece(data, piece);
	while(i < data->piece_y)
	{
		ret = get_next_line(0, &data->line);
		if (ret < 0)
			return (0);
		piece->piece[i] = convert_to_int_piece(data, data->line, piece);
		ft_strdel(&data->line);
		i++;
	}
	piece->piece[i] = NULL;
	return (ret);
}

int	read_piece_size(t_filler *data, int ret)
{
	int	i;
	int	j;

	ret = get_next_line(0, &data->line);
	if (ret < 0)
		return (0);
	if (ft_strnstr(data->line, "Piece", 6))
		return (0);
	i = ft_strchr(data->line, ' ') + 1;
	j = ft_strrchr(data->line, ' ') + 1;
	data->piece_y = ft_atoi(&data->line[i]);
	data->piece_x = ft_atoi(&data->line[j]);
	ft_strdel(&data->line);
	i = 0;
	return (ret);
}
