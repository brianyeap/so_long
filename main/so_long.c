/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 02:05:38 by brian             #+#    #+#             */
/*   Updated: 2024/09/27 20:42:41 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map, char **argv)
{
	map->filename = argv[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		initialize_map(&map, argv);
		check_map(&map);
		map.mlx = mlx_init();
		map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL,
				map.y * IMG_PXL, WND_NAME);
		file_to_image(&map);
		print_map(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("Usage: ./so_long <map.ber>\n\033[0m", 2);
	exit(1);
}
