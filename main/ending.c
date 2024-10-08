/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:10:25 by brian             #+#    #+#             */
/*   Updated: 2024/09/28 20:13:48 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wnd);
	ft_free_array(map->array, map->y);
	exit(0);
}

void	win_screen(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd,
		map->x / 2 * IMG_PXL, map->y / 2 * IMG_PXL, 0xFFFA9E, "YOU WON!");
	ft_putstr_fd("\n\x1b[32;01m", 1);
	ft_putstr_fd("YOU WON !!!\n", 1);
	ft_putstr_fd("\nTotal Moves: ", 1);
	ft_putstr_fd(ft_itoa(map->moves), 1);
	ft_putstr_fd("\n\x1b[0m", 1);
}
