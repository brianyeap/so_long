/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:48:40 by brian             #+#    #+#             */
/*   Updated: 2024/09/26 23:04:08 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_map *map)
{
	int a;
	
	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
		"src/ground.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
		"src/wall.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
		"src/exit.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
		"src/coin.xpm", &a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
		"src/enemy.xpm", &a, &a);
	map->img.player = mlx_xpm_file_to_image(map->mlx,
		"src/player.xpm", &a, &a);
}