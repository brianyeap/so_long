/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:50:28 by brian             #+#    #+#             */
/*   Updated: 2024/09/25 01:26:26 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_free_array(char **array, int i)
{
    while (i > 0)
        free(array[--i]);
    free(array);
    return (0);
}

void ft_freeandexit(t_map *map)
{
    if (map->line)
        free(map->line);
    if (map->file)
        free(map->file);
    if (map->array)
        free(map->array);
    if (map->copy)
        free(map->copy);
    exit(1);
}