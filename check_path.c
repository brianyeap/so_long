/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:46:28 by brian             #+#    #+#             */
/*   Updated: 2024/09/25 01:18:56 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void recursive_check_path(t_map *map, int x, int y)
{
	char type;

	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	recursive_check_path(map, x + 1, y);
	recursive_check_path(map, x - 1, y);
	recursive_check_path(map, x, y + 1);
	recursive_check_path(map, x, y - 1);
}

void	check_path(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	search_player(map);
	recursive_check_path(map, map->player.x, map->player.y);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		ft_putstr_fd("\033[1;31mERROR: ", 2);
		ft_putstr_fd("NO VALID PATH\n\033[0m", 2);
		ft_free_array(map->array, map->y);
		ft_free_array(map->copy, map->y);
		exit(1);
	}
}