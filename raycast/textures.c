/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:48:05 by user42            #+#    #+#             */
/*   Updated: 2020/04/17 12:33:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_texture(t_global *g)
{
	if (g->r->side == 1 || g->r->side == 2)
	{
		g->r->wallx = g->c->pos_y + g->r->walldist * g->r->raydiry;
		g->r->wallx -= floor(g->r->wallx);
		g->r->tex_x = (int)(g->r->wallx * (double)g->i[g->r->side]->width);
		if (g->r->raydirx > 0)
			g->r->tex_x = g->i[g->r->side]->width - g->r->tex_x - 1;
	}
	else if (g->r->side == 3 || g->r->side == 4)
	{
		g->r->wallx = g->c->pos_x + g->r->walldist * g->r->raydirx;
		g->r->wallx -= floor(g->r->wallx);
		g->r->tex_x = (int)(g->r->wallx * (double)g->i[g->r->side]->width);
		if (g->r->raydiry < 0)
			g->r->tex_x = g->i[g->r->side]->width - g->r->tex_x - 1;
	}
}

void	draw_texture(t_global *g, int y)
{
	g->i[0]->img_data[g->r->screenx *
	g->i[0]->bpp / 8 + g->i[0]->sl * y] = g->i[g->r->side]
	->img_data[g->r->tex_x * (g->i[g->r->side]->bpp
		/ 8) + g->r->tex_y * g->i[g->r->side]->sl];
	g->i[0]->img_data[(g->r->screenx *
	g->i[0]->bpp / 8 + g->i[0]->sl * y) + 1] = g->i[g->r->side]
	->img_data[(g->r->tex_x * (g->i[g->r->side]->bpp
		/ 8) + g->r->tex_y * g->i[g->r->side]->sl) + 1];
	g->i[0]->img_data[(g->r->screenx *
	g->i[0]->bpp / 8 + g->i[0]->sl * y) + 2] = g->i[g->r->side]
	->img_data[(g->r->tex_x * (g->i[g->r->side]->bpp
		/ 8) + g->r->tex_y * g->i[g->r->side]->sl) + 2];
}

int		ray_texture(t_global *g, int y)
{
	int i;

	i = 0;
	choose_texture(g);
	g->r->step = 1.0 * g->i[g->r->side]->height
	/ g->r->wall_height;
	g->r->textpos = (g->r->drawstart - g->c->y / 2 + g->r->wall_height / 2)
	* g->r->step;
	while (y < g->r->drawend)
	{
		g->r->tex_y = (int)g->r->textpos &
		(g->i[g->r->side]->height - 1);
		g->r->textpos += g->r->step;
		draw_texture(g, y);
		y++;
		i++;
	}
	return (i);
}
