/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:03:01 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/17 12:33:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_height(t_global *g)
{
	g->r->wall_height = (int)(g->c->y / g->r->walldist);
	g->r->drawstart = -g->r->wall_height / 2 + g->c->y / 2;
	if (g->r->drawstart < 0)
		g->r->drawstart = 0;
	g->r->drawend = g->r->wall_height / 2 + g->c->y / 2;
	if (g->r->drawend >= g->c->y)
		g->r->drawend = g->c->y - 1;
}

int		ray_ceiling(t_global *g, int y)
{
	int	r;
	int	gg;
	int	b;

	r = g->c->c_col % 256;
	gg = (g->c->c_col / 256) % 256;
	b = ((g->c->c_col / 256) / 256) % 256;
	while (y < g->r->drawstart)
	{
		g->i[0]->img_data
			[g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y] = r;
		g->i[0]->img_data
			[(g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y) + 1] =
			gg;
		g->i[0]->img_data
			[(g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y) + 2] =
			b;
		y++;
	}
	return (y);
}

void	ray_floor(t_global *g, int y)
{
	int	r;
	int	gg;
	int	b;

	r = g->c->f_col % 256;
	gg = (g->c->f_col / 256) % 256;
	b = ((g->c->f_col / 256) / 256) % 256;
	while (y < g->c->y)
	{
		g->i[0]->img_data
			[g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y] = r;
		g->i[0]->img_data
			[(g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y) + 1] =
			gg;
		g->i[0]->img_data
			[(g->r->screenx * g->i[0]->bpp / 8 + g->i[0]->sl * y) + 2] =
			b;
		y++;
	}
}

void	draw(t_global *g)
{
	int	y;

	y = 0;
	wall_height(g);
	y = y + ray_ceiling(g, y);
	y = y + ray_texture(g, y);
	ray_floor(g, y);
}
