#include "../so_long.h"

// Initialize game variables to default values
static void	initialize_game_variables(t_game *game)
{
	game->map = NULL;
	game->floodfill_map = NULL;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_hovering_exit = 0;
	game->coins = 0;
	game->exit = 0;
	game->move = 1;
	game->row = 0;
	game->column = 0;
	game->end_game = 0;
}

// Initialize game, render map, and start the game loop
static void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->column * 64,
			game->row * 64, "so_long");
	initialize_assets(game);
	render_map(game);
	mlx_hook(game->window, 02, 1L << 0, key_mapping, game);
	mlx_hook(game->window, 17, 1L << 17, exit_game, game);
	mlx_loop(game->mlx);
}

// Main function: initialize, validate, and start the game
int	main(int argc, char **argv)
{
	t_game	game;	
	int		map_fd;

	initialize_game_variables(&game);
	check_assets(&game);
	check_args(&game, argc, argv);
	map_fd = open(argv[1], 0);
	game.row = get_rows(&game, map_fd);
	close(map_fd);
	map_fd = open(argv[1], 0);
	get_map(&game, map_fd);
	close(map_fd);
	validate_map(&game);
	initialize_game(&game);
	return (0);
}
