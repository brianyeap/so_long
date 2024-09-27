/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:37:02 by brian             #+#    #+#             */
/*   Updated: 2024/09/27 20:46:02 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_filename(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r'
		|| map->filename[len - 2] != 'e'
		|| map->filename[len - 3] != 'b'
		|| map->filename[len - 4] != '.')
	{
		error_filename();
		exit(1);
	}
}

void	check_x_y_size(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = 0;
	i = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (x != i)
			error_size(map);
		y++;
	}
	map->x = i;
}

static void	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->array[0][x] == '1' && map->array[1][x])
		x++;
	if (map->array[0][x] != '\0')
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' &&
			map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y -1][x] == '1')
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

static void	check_params(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'P')
				map->p++;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				error_map_elements(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

void	check_map(t_map *map)
{
	check_filename(map);
	generate_map_array(map);
	check_x_y_size(map);
	check_wall(map);
	check_params(map);
	check_path(map);
	ft_free_array(map->copy, map->y);
}
