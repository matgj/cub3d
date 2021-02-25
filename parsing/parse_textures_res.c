/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:24:30 by user42            #+#    #+#             */
/*   Updated: 2020/04/19 15:20:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_end_space(char *str)
{
	int	l;

	l = ft_strlen(str) - 1;
	while (str[l] == ' ' && l >= 0)
	{
		str[l] = '\0';
		l--;
	}
	return (str);
}

void	create_textures(t_global *g, int flag, char *path)
{
	int	endian;

	if (!(g->i[flag]->img_ptr = mlx_xpm_file_to_image(
			g->r->mlx_ptr, path, &g->i[flag]->width, &g->i[flag]->height)))
		exit_error("textures path looks like shit bro", g);
	g->i[flag]->img_data = mlx_get_data_addr(g->i[flag]->img_ptr,
			&g->i[flag]->bpp, &g->i[flag]->sl, &endian);
}

void	path_spaces(t_global *g, int flag)
{
	if (flag == 1)
		create_textures(g, flag, skip_end_space(g->c->north));
	else if (flag == 2)
		create_textures(g, flag, skip_end_space(g->c->south));
	else if (flag == 3)
		create_textures(g, flag, skip_end_space(g->c->west));
	else if (flag == 4)
		create_textures(g, flag, skip_end_space(g->c->east));
	else if (flag == 5)
		create_textures(g, flag, skip_end_space(g->c->sprite));
}

void	parse_textures(char *line, t_global *g, int flag)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (flag == 1)
		g->c->north = ft_strdup(&line[i]);
	else if (flag == 2)
		g->c->south = ft_strdup(&line[i]);
	else if (flag == 3)
		g->c->west = ft_strdup(&line[i]);
	else if (flag == 4)
		g->c->east = ft_strdup(&line[i]);
	else if (flag == 5)
		g->c->sprite = ft_strdup(&line[i]);
	path_spaces(g, flag);
}

void	parse_res(char *line, t_global *g)
{
	int	i;
	int max_x;
	int max_y;

	i = 0;
	g->c->x = ft_atoi(&line[i]);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	g->c->y = ft_atoi(&line[i]);
	mlx_get_screen_size(g->r->mlx_ptr, &max_x, &max_y);
	if (g->c->x > max_x)
		g->c->x = max_x;
	else if (g->c->x < 1)
		exit_error("this resolution looks like Trump's penis bro... too small!",
		g);
	if (g->c->y > max_y)
		g->c->y = max_y;
	else if (g->c->y < 1)
		exit_error("this resolution looks like Trump's penis bro... too small!",
		g);
	if (!(g->s->buffer = mmalloc(sizeof(double) * (g->c->x + 1))))
		exit_error("problem with memory allocation in parsing resolution", g);
}
