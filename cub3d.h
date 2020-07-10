/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:03:44 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/10 18:45:07 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "./minilibx_og/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

static int worldmap[20][20] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct	s_text
{
	void		*pink;
	int			*pink_data;
	int			pink_height;
	int			pink_width;
	int			pink_sizel;
	int			pink_b;
	int			pink_endi;
	int			textx;
}				t_text;

typedef struct	s_pos
{
	double			x;
	double			y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	int				width;
	int				height;
}				t_pos;

typedef struct	s_map
{
	int				x;
	int				y;
	double			dir_x;
	double			dir_y;
	int				step_x;
    int				step_y;
	int				side;
	char			**map;
	char			**gnl;
}				t_map;

typedef struct	s_draw
{
	int				line_height;
    int				start;
    int				end;
}				t_draw;

typedef struct	s_ray
{
	double			x;
	double			y;
	double 			side_x;
    double			side_y;
	double			delta_x;
	double			delta_y;
	double			wall_dist;
	double			wallx;
}				t_ray;

typedef struct	s_img
{
	void			*ptr;
	int				*data;
	int				sizel;
	int				b;
	int				endi;
}				t_img;

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			img;
}				t_data;

typedef struct	s_all
{
	t_text			*text;
	t_pos			*pos;
	t_map			*map;
	t_draw			*draw;
	t_ray			*ray;
	t_data			*data;
}				t_all;

int		start_window(t_all *all, int ac, char **av);
void	start_struct(t_pos *pos, t_map *map);
void    start_parse(t_all *all, char *cub);
int		ft_error(int len, char *str);
char	**copy_lines(char **gnl, int fd);
int		get_next_line(int fd, char **line);
char	*del_line(char *s);
int		check_new(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_line(char *s1);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
void    start_texture(t_text *text, t_data *data);
int		ft_keypress(int key, t_all *all);
void	ft_rotate(int b, t_map *map, t_pos *pos);
void	ft_forback(int b, t_pos *pos, t_map *map);
void	ft_leftright(int b, t_pos *pos, t_map *map);
void	ft_close(int b, t_data *data);
int		print_game(t_all *all);
void	raycast(t_pos *pos, t_map *map, t_ray *ray, t_data *data, t_draw *draw, t_text *text);
void	start_raycast(t_pos *pos, t_map *map, t_ray *ray, int x);
void	find_step(t_ray *ray, t_pos *pos, t_map *map);
void	wall_hit(t_ray *ray, t_map *map);
void	wall_dist(t_map *map, t_ray *ray, t_pos *pos);
void	draw_line(t_text *text, t_draw *draw, t_data *data, t_pos *pos, int x);
void	line_height(t_ray *ray, t_draw *draw, t_pos *pos);

#endif