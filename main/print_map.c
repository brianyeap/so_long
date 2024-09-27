/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:13:26 by brian             #+#    #+#             */
/*   Updated: 2024/09/27 21:33:05 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	plot_map(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	(void)type;
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
}

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			plot_map(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		y++;
	}
}

void	print_moves(t_map *map)
{
	char	*moves;

	moves = ft_itoa(map->moves);
	ft_putstr_fd("\n\x1b[32;01m", 1);
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(moves, 1);
	ft_putstr_fd("\n\x1b[0m", 1);
	free(moves);
}
