/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:56:40 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/17 16:45:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	color_check(int r, int gg, int b, t_global *g)
{
	if (r > 255 || r < 0 || gg > 255 || g < 0 || b > 255 || b < 0)
		exit_error("colors values < 0 or > 255 brooo", g);
}

void	parse_ray_floor(char *line, t_global *g)
{
	int	i;
	int	f_r;
	int	f_g;
	int	f_b;

	i = 0;
	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == '\0')
		exit_error("write some floor color bro!", g);
	f_r = ft_atoi(line);
	while (line[i] != ',')
		i++;
	f_g = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	f_b = ft_atoi(line + i + 1);
	color_check(f_r, f_g, f_b, g);
	g->c->f_col = f_r;
	g->c->f_col = (g->c->f_col << 8) + f_g;
	g->c->f_col = (g->c->f_col << 8) + f_b;
}

void	parse_ray_ceiling(char *line, t_global *g)
{
	int	i;
	int	c_r;
	int	c_g;
	int	c_b;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == '\0')
		exit_error("write some ceiling color bro!", g);
	c_r = ft_atoi(line);
	while (line[i] != ',')
		i++;
	c_g = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	c_b = ft_atoi(line + i + 1);
	color_check(c_r, c_g, c_b, g);
	g->c->c_col = c_r;
	g->c->c_col = (g->c->c_col << 8) + c_g;
	g->c->c_col = (g->c->c_col << 8) + c_b;
}
