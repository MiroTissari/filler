/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:34 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 14:57:36 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_players(t_filler *data, int ret)
{
	char	**temp;

	ret = get_next_line(0, &data->line);
	if (ret != 1)
		return (ret);
	temp = ft_strsplit(data->line, ' ');
	ft_strdel(&data->line);
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
	ft_2d_free(temp);
	return (ret);
}
