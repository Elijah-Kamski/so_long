#include "../so_long.h"

// Display map elements based on characters and positions
static void	put_map(int x, int y, char c, t_game *game)
{
	int	size;

	size = 64;
	if (c == '1')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.wall, x * size, y * size);
	else if (c == '0')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.floor, x * size, y * size);
	else if (c == 'P')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.player, x * size, y * size);
	else if (c == 'C')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.coin, x * size, y * size);
	else if (c == 'E')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.exit, x * size, y * size);
	else if (c == 'O')
		mlx_put_image_to_window
		(game->mlx, game->window, game->img.on_exit, x * size, y * size);
}

// Render the map and update textures
int	render_map(t_game *game)
{
	int	y;
	int	x;
	int	size;

	size = 64;
	if (game->coins == 0)
	{
		mlx_destroy_image(game->mlx, game->img.exit);
		game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	}
	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->column)
		{
			put_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
