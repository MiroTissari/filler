/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:34 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 15:04:25 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"

int	get_players_test(t_filler *data)
{
	if (ft_strstr(data->line, "p1"))
	{
		data->boss_sign = 'O';
		data->boss_sign_s = 'o';
		data->enemy_sign = 'X';
		data->enemy_sign_s = 'x';
	}
	else if (ft_strstr(data->line, "p2"))
	{
		data->boss_sign = 'X';
		data->boss_sign_s = 'x';
		data->enemy_sign = 'O';
		data->enemy_sign_s = 'o';
	}
	else
		return (0);
	printf("get_players\n");
	ft_strdel(&data->line);
	return (1);
}
