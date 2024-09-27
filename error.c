/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:05:48 by brian             #+#    #+#             */
/*   Updated: 2024/09/23 16:03:12 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_filename(void)
{
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("Filename should be a BER extension file\n\033[0m", 2);
	exit(1);
}

void	error_openfile(void)
{
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("failed open\n\033[0m", 2);
	exit(1);
}

void	error_size(t_map *map)
{
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("failed size\n\033[0m", 2);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
	exit(1);
}

void	error_wall(t_map *map)
{
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("failed wall\n\033[0m", 2);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
	exit(1);
}

void	error_map_elements(t_map *map)
{
	ft_putstr_fd("\033[1;31mERROR: ", 2);
	ft_putstr_fd("failed elements\n\033[0m", 2);
    ft_free_array(map->array, map->y);
    ft_free_array(map->copy, map->y);
	exit(1);
}

