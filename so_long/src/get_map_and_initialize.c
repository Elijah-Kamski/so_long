#include "../so_long.h"

// Read rows from the file, validate, and return the count
int	get_rows(t_game *game, int fd)
{
	char	*content_row;
	int		rows;

	rows = 0;
	content_row = get_next_line(fd);
	while (content_row)
	{
		rows++;
		if (*content_row == '\n')
		{
			free(content_row);
			free_and_quit("Invalid map.", game, 1);
		}
		free(content_row);
		content_row = get_next_line(fd);
	}
	if (rows == 0)
		free_and_quit("The file is empty or does not exist.", game, 1);
	free(content_row);
	return (rows);
}

// Read and allocate memory for the map from the file
void	get_map(t_game *game, int fd)
{
	int		i;
	char	*content_row;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->row + 1));
	game->floodfill_map = (char **)malloc(sizeof(char *) * (game->row + 1));
	if (!game->map || !game->floodfill_map)
		free_and_quit("Malloc error.", game, 4);
	while (i < game->row)
	{
		content_row = get_next_line(fd);
		game->map[i] = ft_strtrim(content_row, "\n");
		game->floodfill_map[i] = ft_strtrim(content_row, "\n");
		free(content_row);
		i++;
	}
	get_next_line(fd);
	game->map[i] = NULL;
	game->floodfill_map[i] = NULL;
	game->column = ft_strlen(game->map[i - 1]);
}

// Initialize game assets from XPM files
void	initialize_assets(t_game *game)
{
	int	size;

	size = 64;
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, COIN, &size, &size);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, 
			EXIT_HIDDEN, &size, &size);
	game->img.on_exit = mlx_xpm_file_to_image(game->mlx, ON_EXIT, &size, &size);
}
