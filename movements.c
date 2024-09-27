/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:15:58 by brian             #+#    #+#             */
/*   Updated: 2024/09/26 23:04:13 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->array[y][x] == 'E' && map->c == 0)
		return (win_screen(map));
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
}

void move_up(t_map *map)
{
	int x;
	int y;

	x = map->player.x;
	y = map->player.y;
	if (map->array[y - 1][x] != '1' && y > 0)
	{
		move(map, x, y, UP);
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL + 8, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.x = x;
		print_moves(map);
	}
}

void move_down(t_map *map)
{
	int x;
	int y;

	x = map->player.x;
	y = map->player.y;
	if (map->array[y + 1][x] != '1' && y < map->y)
	{
		move(map, x, y, DOWN);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL + 8, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.y = y;
		print_moves(map);
	}
}

void move_left(t_map *map)
{
	int x;
	int y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		move(map, x, y, LEFT);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL + 8, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.x = x;
		print_moves(map);
	}
}

void	move_right(t_map *map)
{
	int x;
	int y;

	x = map->player.x;
	y = map->player.y;
	
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move(map, x, y, RIGHT);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * IMG_PXL + 8, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.y = y;
		print_moves(map);
	}
}