#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct s_filler
{
	int			boss;
	int			enemy;
	int			boss_sign;
	int			enemy_sign;
	int			boss_sign_s;
	int			enemy_sign_s;
	int			first_round;

	int			**map;
	char		*line;
	int			mapsize_x;
	int			mapsize_y;

	s_piece		*piece;
	int			piece_x;
	int			piece_y;
}				t_filler;

typedef struct s_piece
{
	int			**piece;
	
}				t_piece;

int		main(void);

int		get_players(t_filler *data, int ret);

int		get_map_and_piece(t_filler *data, int ret);
int		check_map_size(t_filler *data, int ret);

int		read_piece_size(t_filler *data, int ret);
int		read_piece(t_filler *data, t_piece *piece, int ret);


#endif
