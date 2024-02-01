#include "../../so_long.h"

// Check command-line arguments
// Exit with specific codes if conditions are not met
void	check_args(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		free_and_quit("Invalid number of arguments.", game, 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		free_and_quit("File must be of type .ber", game, 1);
}

// Check the existence of required textures
void	check_assets(t_game *game)
{
	const char	*assets[7] = {
		"./assets/textures/player.xpm",
		"./assets/textures/exit_hidden.xpm",
		"./assets/textures/coin.xpm",
		"./assets/textures/exit_hovered.xpm",
		"./assets/textures/exit.xpm",
		"./assets/textures/wall.xpm",
		"./assets/textures/floor.xpm"
	};
	int			fd;
	int			i;

	i = 0;
	while (i <= 6)
	{
		fd = open(assets[i], 0);
		close(fd);
		if (fd == -1)
			free_and_quit("Texture missing.", game, 3);
		i++;
	}
}
