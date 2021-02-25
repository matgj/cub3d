/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:54:55 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/21 15:33:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 32
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"

typedef	struct		s_ray
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		camx;
	int			screenx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			wall_height;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			tex_x;
	int			tex_y;
	double		step;
	double		textpos;
}					t_ray;

typedef	struct		s_config
{
	char		*map_1d;
	char		**tmp_map_2d;
	char		**map;
	double		pos_x;
	double		pos_y;
	int			max_x;
	int			max_y;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			c_col;
	int			f_col;
}					t_config;

typedef	struct		s_sprite
{
	int			nb_sprite;
	double		*buffer;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			d;
	int			texx;
	int			texy;
}					t_sprite;

typedef struct		s_image
{
	void		*img_ptr;
	char		*img_data;
	int			width;
	int			height;
	int			bpp;
	int			sl;
}					t_image;

typedef	struct		s_z_sprite
{
	int			x;
	int			y;
	double		s_dist;
}					t_z_sprite;

typedef	struct		s_global
{
	char		*image;
	int			fd:4;
	int			cpt;
	t_config	*c;
	t_ray		*r;
	t_image		**i;
	t_sprite	*s;
	t_z_sprite	**z;
}					t_global;

typedef struct		s_bmp
{
	unsigned char	*f;
	unsigned char	*i;
	unsigned char	*bmppad;
	unsigned int	w;
	unsigned int	h;
	char			*data;
}					t_bmp;

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isspace(char c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char *str);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_cpy_line(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_check_bn(char *str);
int					get_next_line(int fd, char **line);

void				*mmalloc(unsigned int size);
void				*mrealloc(void *ptr, size_t size);
int					free_all_malloc(void);
int					mfree(void *to_free);
extern t_list		*g_all_mmalloc;

int					close_win(t_global *g);
void				exit_error(char *str, t_global *g);
void				exit_begin(char *str, t_global *g);
int					red_x(t_global *g);

void				parse_info(int fd, t_global *g);
void				init_struct_ptr(t_global *g);
void				sort_infos(char *line, t_global *g);
char				*skip_spaces(char *str);
void				parse_map(int fd, t_global *g);
char				*clean_line(char *line, t_global *g);
int					line_length(char *line);
int					is_map_char(char c);
char				*skip_end_space(char *str);
void				path_spaces(t_global *g, int flag);
void				create_texture(t_global *g, int flag, char *path);
void				parse_textures(char *line, t_global *g, int flag);
void				parse_res(char *line, t_global *g);
void				parse_ray_ceiling(char *line, t_global *g);
void				parse_ray_floor(char *line, t_global *g);
void				color_check(int r, int gg, int b, t_global *g);
void				create_map(t_global *g);
void				init_map(t_global *g);
void				map_size(t_global *g);
void				fill_map(t_global *g);
void				check_map(t_global *g, int x, int y);

void				hook(t_global *g);
int					raycast_image(t_global *g);

int					key_management(int key, t_global *g);

void				raycasting(t_global *g);
void				init_var(t_global *g);
void				set_player(t_global *g, int x, int y);
void				sidedist(t_global *g);

void				draw(t_global *g);
void				wall_height(t_global *g);
int					ray_ceiling(t_global *g, int y);
int					ray_texture(t_global *g, int y);
void				set_texture(t_global *g);
void				which_wall(t_global *g);
void				ray_floor(t_global *g, int y);

void				rotate(t_global *g, int key);
void				right(t_global *g);
void				left(t_global *g);
void				backward(t_global *g);
void				forward(t_global *g);

void				init_sprite(t_global *g);
void				pos_sprite(t_global *g);
void				ray_sprite(t_global *g);
int					is_black(t_global *g, int y);
void				sprite(t_global *g);
void				sprite_start_end(t_global *g);
void				sort_sprites(t_global *g);

void				bmp(t_global *g, int w, int h);

#endif
