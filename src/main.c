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
		printf("p_a: %f\n", cub.player->p_a);
		ft_game_loop(&cub);
		//ft_print_split(cub.split_input);
	}
	return (0);
}
