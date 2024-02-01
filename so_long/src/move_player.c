#include "../so_long.h"

// Check if the move is valid and update game state
static int	is_valid_move(t_game *game, int col, int row, int pressed_key)
{
	game->temp = '0';
	if (game->map[row][col] == '1')
		return (0);
	if (game->map[row][col] == 'C')
		game->coins--;
	if (game->map[row][col] == 'E' && game->coins > 0)
	{
		game->player_hovering_exit = 1;
		game->temp = 'O';
		return (1);
	}
	if (game->map[row][col] == 'E' && game->coins == 0)
	{
		game->end_game = 1;
		ft_printf("Moves: %d\n", game->move++);
		ft_printf("\nYOU WIN !!!\n\n");
		exit_game(game);
	}
	if (pressed_key != W && pressed_key != ARROW_UP 
		&& pressed_key != S && pressed_key != ARROW_DOWN
		&& pressed_key != A && pressed_key != ARROW_LEFT
		&& pressed_key != D && pressed_key != ARROW_RIGHT)
		return (0);
	else
		return (1);
}

// Move the player and update the game state based on valid moves
static void	move_player(t_game *game, int col, int row, int pressed_key)
{
	int	is_valid;
	int	temp_col;
	int	temp_row;

	temp_col = game->player_x;
	temp_row = game->player_y;
	is_valid = is_valid_move(game, col, row, pressed_key);
	if (is_valid == 1)
	{
		game->player_y = row;
		game->player_x = col;
		if (game->temp != 'O')
			game->map[row][col] = 'P';
		else
			game->map[row][col] = 'O';
		if (game->map[temp_row][temp_col] != 'O')
			game->map[temp_row][temp_col] = '0';
		else
			game->map[temp_row][temp_col] = 'E';
		ft_printf("Moves: %d\n", game->move++);
		render_map(game);
	}
}

// Handle keyboard input and update game state
int	key_mapping(int keycode, t_game *game)
{
	int	col;
	int	row;

	col = game->player_x;
	row = game->player_y;
	if (keycode == W || keycode == ARROW_UP)
		row--;
	else if (keycode == A || keycode == ARROW_LEFT)
		col--;
	else if (keycode == S || keycode == ARROW_DOWN)
		row++;
	else if (keycode == D || keycode == ARROW_RIGHT)
		col++;
	else if (keycode == ESC)
		exit_game(game);
	if (game->end_game != 1)
		move_player(game, col, row, keycode);
	return (0);
}
