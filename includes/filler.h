/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:47 by mtissari          #+#    #+#             */
/*   Updated: 2022/10/14 19:07:11 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define END		0
# define BAD_MAP	-1
# define BAD_PIECE	-2
# define BAD_INPUT	-3
# define BAD_PLAYER	-4
# define BAD_MALLOC	-5

typedef struct s_filler
{
	int				boss;
	int				enemy;
	int				boss_sign;
	int				enemy_sign;
	int				boss_sign_s;
	int				enemy_sign_s;
	int				target;
	int				error;

	int				**map;
	char			*line;
	int				mapsize_x;
	int				mapsize_y;
	int				best_val;
	int				best_x;
	int				best_y;
	int				piece_x;
	int				piece_y;
}					t_filler;

typedef struct s_piece
{
	int				**piece;
	int				found;
	int				temp_value;
}					t_piece;

int		main(void);
int		error_handling(t_filler *data, int err_nb);

int		free_all(t_filler *data);
int		reset_data(t_filler *data, t_piece *piece);
int		init_piece(t_filler *data, t_piece *piece);
void	init_t_filler(t_filler *data);

int		get_players(t_filler *data);

int		get_map(t_filler *data);

int		get_piece(t_filler *data, t_piece *piece);

void	create_heat_map(t_filler *data);

int		get_coords(t_filler *data, t_piece *piece);

#endif
