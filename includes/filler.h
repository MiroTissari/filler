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

#ifndef FILLER_H
# define FILLER_H

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
	int			actual_size;
	int			temp_value;
}				t_piece;
/*
int		main(void);

int		get_players(t_filler *data, int ret);

int		get_map_and_piece(t_filler *data, int ret);
int		check_map_size(t_filler *data, int ret);

int		read_piece_size(t_filler *data, int ret);
int		read_piece(t_filler *data, t_piece *piece, int ret);
*/
void	create_heat_map(t_filler *data);

void	get_coords(t_filler *data);

int	make_grid(t_filler *data, int fd);
int		get_players(t_filler *data, int ret);
int	get_map_and_piece(t_filler *data, int fd);
int	check_map_size(t_filler *data, int fd);
int	read_piece_size(t_filler *data, int fd);
int	read_piece(t_filler *data, t_piece *piece, int fd);

#endif
