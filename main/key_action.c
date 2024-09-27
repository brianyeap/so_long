/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:37:44 by brian             #+#    #+#             */
/*   Updated: 2024/09/27 21:33:12 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		map->player.x = 0;
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.y++;
	}
}

int	key_hook(int keypressed, t_map *map)
{
	search_player(map);
	if (keypressed == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (keypressed == UP)
		move_up(map);
	else if (keypressed == DOWN)
		move_down(map);
	else if (keypressed == LEFT)
		move_left(map);
	else if (keypressed == RIGHT)
		move_right(map);
	return (0);
}
