#include "../../so_long.h"

// Check and update counts based on map characters
static void	check_char(t_game *game, char c, int row, int col)
{
	if (c == 'C')
		game->coins++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->player_x = col;
		game->player_y = row;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		free_and_quit("Invalid characters.", game, 2);
}

// Check map validity
// Count elements and exit with specific codes for invalid scenarios
static void	check_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row] != NULL)
	{
		col = -1;
		while (game->map[row][++col])
			check_char(game, game->map[row][col], row, col);
		row++;
	}
	if (game->player == 0)
		free_and_quit("No player in the map.", game, 2);
	else if (game->player > 1)
		free_and_quit("More than one player in map.", game, 2);
	else if (game->coins == 0)
		free_and_quit("No coins in map.", game, 2);
	else if (game->exit == 0)
		free_and_quit("No exit in map.", game, 2);
	else if (game->exit > 1)
		free_and_quit("More than one exit in map.", game, 2);
}

// Check if the map is surrounded by walls.
static void	check_walls(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[0][col] != '1' ||
				game->map[game->row - 1][col] != '1')
				free_and_quit("Map is not surrounded by walls", game, 2);
			if (game->map[row][0] != '1' ||
				game->map[row][game->column - 1] != '1')
				free_and_quit("Map is not surrounded by walls", game, 2);
			col++;
		}
		row++;
	}
}

// Check if there is a valid path on the map using floodfill
void	check_path(t_game *game)
{
	if (!floodfill(game))
		free_and_quit("Map does not have a valid path", game, 2);
	free_floodfill_map(game);
}

// Perform map validations, check walls, and validate the path
void	validate_map(t_game *game)
{
	check_map(game);
	if (game->column <= 0)
		free_and_quit("Invalid number of columns.", game, 2);
	if (game->row <= 0)
		free_and_quit("Invalid number of rows.", game, 2);
	check_walls(game);
	check_path(game);
}
