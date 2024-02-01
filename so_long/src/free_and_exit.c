#include "../so_long.h"

// Free allocated memory for the map
static void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

// Display error message, free allocated memory, and exit with a code
void	free_and_quit(char *s, t_game *game, int exit_code)
{
	ft_printf("Error\n%s\n", s);
	if (game->map != NULL)
		free_map(game);
	if (game->floodfill_map != NULL)
		free_floodfill_map(game);
	if (exit_code == 1)
		ft_printf("File is not a valid map. Please select a valid .ber file");
	if (exit_code == 2)
		ft_printf("Map is not valid. Please fix it and try again.");
	exit(exit_code);
}

// Free allocated memory for the floodfill map
void	free_floodfill_map(t_game *game)
{
	int	i;

	if (!game->floodfill_map)
		return ;
	i = 0;
	while (game->floodfill_map[i])
	{
		free(game->floodfill_map[i]);
		i++;
	}
	free(game->floodfill_map);
	game->floodfill_map = NULL;
}

// Free resources and exit the game
int	exit_game(t_game *game)
{
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.on_exit)
		mlx_destroy_image(game->mlx, game->img.on_exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(game);
	free(game->mlx);
	exit(0);
}
