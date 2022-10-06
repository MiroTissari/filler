/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:47 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/05 18:00:01 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H

# include "../libft/libft.h"
# include <stdio.h>

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
	int			ret;

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

void	create_heat_map(t_filler *data);

int		get_coords(t_filler *data);

int		get_players(t_filler *data, int fd);
int		get_map_and_piece(t_filler *data, int fd);
int		check_map_size(t_filler *data, int fd);
int		read_piece_size(t_filler *data, int fd);
int		read_piece(t_filler *data, t_piece *piece, int fd);

#endif
