#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "./libs/libft/libft.h"
# include "./libs/minilibx/mlx.h"

// Assets
# define PLAYER "./assets/textures/player.xpm"
# define COIN "./assets/textures/coin.xpm"
# define WALL "./assets/textures/wall.xpm"
# define FLOOR "./assets/textures/floor.xpm"
# define EXIT_HIDDEN "./assets/textures/exit_hidden.xpm"
# define ON_EXIT "./assets/textures/exit_hovered.xpm"
# define EXIT "./assets/textures/exit.xpm"

// Control Atribution - WASD + ESC
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

// Control Atribution - Arrows
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

typedef struct s_img
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*on_exit;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*window;
	char	**map;
	char	**floodfill_map;
	char	temp;
	int		player;
	int		player_gamey;
	int		player_x;
	int		player_y;
	int		player_hovering_exit ;
	int		coins;
	int		exit;
	int		row;
	int		column;
	int		end_game;
	int		move;
}	t_game;

//checks
void		check_assets(t_game *game);
void		check_args(t_game *game, int argc, char **argv);
void		check_path(t_game *game);
int			floodfill(t_game *game);

//map
void		validate_map(t_game *game);
int			get_rows(t_game *game, int fd);
void		get_map(t_game *game, int fd);
void		free_and_quit(char *s, t_game *game, int exit_code);
void		initialize_assets(t_game *game);
int			render_map(t_game *game);

//free and exit
int			exit_game(t_game *game);
void		free_floodfill_map(t_game *game);

//other
int			key_mapping(int keycode, t_game *game);

#endif
