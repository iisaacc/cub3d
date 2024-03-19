#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		ft_error_msg("Introduce a single argument specifying a .cub valid map.", NULL);
	else
	{
		if (ft_parser(argv[1], &cub) == 1)
			return (1);
		ft_game_loop(&cub);
	}
	return (0);
}