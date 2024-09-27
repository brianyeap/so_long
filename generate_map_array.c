/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:39:00 by brian             #+#    #+#             */
/*   Updated: 2024/09/25 01:27:16 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void generate_map_array(t_map *map)
{
    int	fd;
	
	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		error_openfile();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
			map->file = ft_strjoinandfree(map->file, map->line);
			free(map->line);
			if (!map->file)
				ft_freeandexit(map);
			map->y++;
	}
	close(fd);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if(!map->array || !map->copy)
		ft_freeandexit(map);
	free(map->file);
}