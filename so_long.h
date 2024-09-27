/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 02:33:05 by brian             #+#    #+#             */
/*   Updated: 2024/09/26 23:05:58 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
# include "./minilibx-mac-osx/mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

#include <stdio.h>

// Configs
# define UP      13
# define DOWN    1
# define LEFT    0
# define RIGHT   2
# define IMG_PXL 50
# define ESC     53
# define WND_NAME "so_long"

typedef struct s_player
{
	int	y;
	int	x;

}t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player;
	void	*enemy;
}t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;
}t_map;

// Error
void	error_filename(void);
void	error_openfile(void);
void	error_size(t_map *map);
void	error_wall(t_map *map);
void	error_map_elements(t_map *map);

// Check
void 	check_map(t_map *map);
void 	search_player(t_map *map);
void	check_path(t_map *map);

// Free
void ft_freeandexit(t_map *map);
int ft_free_array(char **array, int i);

void generate_map_array(t_map *map);
void file_to_image(t_map *map);

// end screen
int		ft_close(t_map *map);
void win_screen(t_map *map);

// print map
void print_map(t_map *map);
void print_moves(t_map *map);

// hook
int	key_hook(int keypressed, t_map *map);

//movement
void move_up(t_map *map);
void move_down(t_map *t_map);
void move_left(t_map *map);
void move_right(t_map *map);


#endif