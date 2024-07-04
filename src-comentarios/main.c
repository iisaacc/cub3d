#include "../includes/cub3d.h"

// void ft_leaks(void) {
// 	system("leaks cub3D");
//     printf("Checking for leaks...\n");
// }

int	main(int argc, char **argv)
{
	// atexit(ft_leaks);
	t_cub	cub;

	if (argc != 2)
		ft_error_msg("Introduce a single argument specifying a .cub valid map.", NULL);
	else
	{
		if (ft_parser(argv[1], &cub) == 1)
			return (1);
		printf("p_a: %f\n", cub.player->p_a);
		ft_game_loop(&cub);
	}
	return (0);
}
