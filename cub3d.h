/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:03:44 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/30 15:50:25 by deannapiedr      ###   ########.fr       */
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

typedef struct	s_text
{
	char			*txt1_p;
	char			*txt2_p;
	char			*txt3_p;
	char			*txt4_p;
	void			*text1;
	int				*text1_data;
	int				text1_height;
	int				text1_width;
	int				text1_sizel;
	int				text1_b;
	int				text1_endi;
	void			*text2;
	int				*text2_data;
	int				text2_height;
	int				text2_width;
	int				text2_sizel;
	int				text2_b;
	int				text2_endi;
	void			*text3;
	int				*text3_data;
	int				text3_height;
	int				text3_width;
	int				text3_sizel;
	int				text3_b;
	int				text3_endi;
	void			*text4;
	int				*text4_data;
	int				text4_height;
	int				text4_width;
	int				text4_sizel;
	int				text4_b;
	int				text4_endi;
	int				*text_data;
	int				text_sizel;
	int				text_height;
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
	char			playerpos;			
}				t_pos;

typedef struct	s_map
{
	int				x;
	int				y;
	int				max_x;
	int				max_y;
	double			dir_x;
	double			dir_y;
	int				step_x;
    int				step_y;
	int				side;
	int				**worldmap;
	char			**map;
	char			**gnl;
}				t_map;

typedef struct	s_draw
{
	int				line_height;
    int				start;
    int				end;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceil_r;
	int				ceil_g;
	int				ceil_b;
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
	char			walldir;
	double			wallx;
}				t_ray;

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*i_data;
	int				sizel;
	int				b;
	int				endi;
}				t_data;

typedef struct	s_all
{
	t_text			*text;
	t_pos			*pos;
	t_map			*map;
	t_draw			*draw;
	t_ray			*ray;
	t_data			*data;
	int				res;
	int				floor;
	int				ceiling;
	int				txt1;
	int				txt2;
	int				txt3;
	int				txt4;
	int				textx;
}				t_all;

int			start_window(t_all *all, int ac, char **av);
void    	start_parse(t_all *all, char *cub);
int			ft_error(int len, char *str);
char		**copy_lines(char **gnl, int fd);
int			get_next_line(int fd, char **line);
char		*del_line(char *s);
int			check_new(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_line(char *s1);
size_t		ft_strlen(const char *str);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		init_params(t_all *all);
char		**sort_parameters(char **gnl, t_all *all);
int			ft_line(char c, char *str, t_all *all);
void		check_error(char *str);
void		ft_ceiling(char *str, t_all *all);
void		ft_floor(char *str, t_all *all);
void		ft_res(char *str, t_all *all);
static int	numlen(const char *str);
int			ft_atoi(const char *str);
int			ft_atoifc(const char *str);
void		ft_map(char **map, t_all *all);
int			ft_findx(char **map);
void		ft_startmap(t_all *all);
void		ft_fillmap(char **map, t_all *all);
void		txt_init(t_text *text, t_data *data);
void		assign_text(t_text *text, t_ray *ray);
void    	start_texture(t_all *all, char *str, int c);
void		texture_check(int c, t_all *all);
void		texture_checkcont(t_all *all, int c);
void		ft_player(t_all *all);
int			start_player(int x, int y, char spawn, t_all *all);
void		ns_point(char spawn, t_all *all);
void		we_point(char spawn, t_all *all);
int			ft_keypress(int key, t_all *all);
void		ft_rotate(int b, t_map *map, t_pos *pos);
void		ft_forback(int b, t_pos *pos, t_map *map);
void		ft_leftright(int b, t_pos *pos, t_map *map);
void		ft_close(int b, t_data *data);
int			print_game(t_all *all);
void		raycast(t_all *all);
void		start_raycast(t_pos *pos, t_map *map, t_ray *ray, int x);
void		find_step(t_ray *ray, t_pos *pos, t_map *map);
void		wall_hit(t_ray *ray, t_map *map);
void		wall_dist(t_map *map, t_ray *ray, t_pos *pos);
void		draw_line(t_all *all, int x);
int			conv_color(int red, int green, int blue);
void		line_height(t_ray *ray, t_draw *draw, t_pos *pos);

#endif