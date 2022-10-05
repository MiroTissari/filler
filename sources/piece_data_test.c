/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_data_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:18 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 18:03:38 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_piece(t_filler *data, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	piece->piece = (int **)malloc(sizeof(int *) * data->piece_y);
	if (!piece->piece)
		return (0);
	while (i < data->piece_y)
	{
		printf("check[%i] of [%i]\t\t\t", i, data->piece_y - 1);
		piece->piece[i] = (int *)malloc(sizeof(int) * data->piece_x);
		if (!piece->piece[i])
			return (0);
		j = 0;
		while (j < data->piece_x)
		{
			piece->piece[i][j] = 0;
			printf("%i", piece->piece[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	piece->actual_size = 0;
	piece->temp_value = 0;
	return (1);
}

void	convert_to_int_piece(t_filler *data, char *line, t_piece *piece, int i)
{
	int	j;

	j = 0;
	printf("converting piece[%i]\n\t\t\t", i);
	while (line[j] != '\0' && j < data->piece_x)
	{
		if (line[j] == '.')
			piece->piece[i][j] = 0;
		else if (line[j] == '*')
		{
			piece->piece[i][j] = -3;
			piece->actual_size++;
		}
		printf("%i ", piece->piece[i][j]);
		j++;
	}
}

int	read_piece(t_filler *data, t_piece *piece, int fd)
{
	int	i;
	int	ret;
//	char	*temp;

	i = 0;
	ret = 1;
	//temp = NULL;
	if (!init_piece(data, piece))
		return (0);
	printf("read_piece\n");
	printf("line:%s\n", data->line);
	while(i < data->piece_y && ret == 1)
	{
		printf("check:::%i\n", piece->piece[i][i]);
		printf("check00000\n");
		ret = get_next_line(fd, &data->line);
		printf("check2121\n");
		if (ret != 1)
			return (0);
		convert_to_int_piece(data, data->line, piece, i);
		printf("\t\t\tpiece: %s\n", data->line);
		//ft_strdel(&data->line);
		printf("check\n");
		i++;
	}
	return (ret);
}

int	read_piece_size(t_filler *data, int fd)
{
	int	i;
	int	j;
	int	ret;

	printf("\npiece size\n");
	ret = get_next_line(fd, &data->line);
	if (ret != 1)
		return (0);
	if (ft_strncmp(data->line, "Piece", 5))
		return (0);
	i = ft_strchr_place(data->line, ' ') + 1;
	j = ft_strrchr_place(data->line, ' ') + 1;
	data->piece_y = ft_atoi(&data->line[i]);
	data->piece_x = ft_atoi(&data->line[j]);
	//ft_strdel(&data->line);
	i = 0;
	printf("\tpiece size y: %i\n", data->piece_y);
	printf("\tpiece size x: %i\n", data->piece_x);
	return (ret);
}
