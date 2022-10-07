/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:47 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/07 14:46:30 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_filler
{
	int			boss;
	int			enemy;
	int			boss_sign;
	int			enemy_sign;
	int			boss_sign_s;
	int			enemy_sign_s;
	int			first_round;
	int			target;
	int			fd;

	int			**map;
	char		*line;
	int			mapsize_x;
	int			mapsize_y;
	int			best_val;
	int			best_x;
	int			best_y;

	struct s_piece		*piece;
	int			piece_x;
	int			piece_y;
}				t_filler;

typedef struct s_piece
{
	int			**piece;
	int			found;
	int			temp_value;
}				t_piece;

int		free_all(t_filler *data, int ret);
int		reset_data(t_filler *data);
void	init_t_filler(t_filler *data);

int		get_players_test(t_filler *data);

int		get_map(t_filler *data);

int		get_piece(t_filler *data);

void	create_heat_map(t_filler *data);

int		get_coords(t_filler *data);

#endif