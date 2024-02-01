#include "../../so_long.h"

// Recursively fill and validate the map using floodfill
static bool	fill(t_game *game, char start, int row, int col)
{
	static bool		exit_found = false;
	static int		coins_caught = 0;

	if (row < 0 || col < 0 || row >= game->row || col >= game->column)
		return (false);
	else if (game->floodfill_map[row][col] == 'F')
		return (false);
	else if (game->floodfill_map[row][col] == '1')
		return (false);
	else if (game->floodfill_map[row][col] == 'E')
		exit_found = true;
	if (game->floodfill_map[row][col] == 'C')
		coins_caught++;
	game->floodfill_map[row][col] = 'F';
	fill(game, start, row + 1, col);
	fill(game, start, row, col + 1);
	fill(game, start, row - 1, col);
	fill(game, start, row, col - 1);
	return (coins_caught == game->coins && exit_found);
}

// Perform floodfill from the player's position and validate the map
int	floodfill(t_game *game)
{
	char	start;
	int		row;
	int		col;
	bool	is_map_valid;

	start = game->floodfill_map[game->player_y][game->player_x];
	row = game->player_y;
	col = game->player_x;
	is_map_valid = fill(game, start, row, col);
	return (is_map_valid);
}
