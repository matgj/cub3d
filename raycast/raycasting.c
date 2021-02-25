/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mathis <Mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:02:39 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/03 13:45:12 by Mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	which_wall(t_global *g)
{
	g->r->hit = 1;
	if (!g->r->side)
	{
		if (g->r->raydirx < 0)
			g->r->side = 1;
		else if (g->r->raydirx > 0)
			g->r->side = 2;
	}
	else if (g->r->side == 1)
	{
		if (g->r->raydiry < 0)
			g->r->side = 3;
		else if (g->r->raydiry > 0)
			g->r->side = 4;
	}
}

void	walldist(t_global *g)
{
	g->r->hit = 0;
	g->r->side = 0;
	while (g->r->hit == 0)
	{
		if (g->r->sidedistx < g->r->sidedisty)
		{
			g->r->sidedistx += g->r->deltadistx;
			g->r->mapx += g->r->stepx;
			g->r->side = 0;
		}
		else
		{
			g->r->sidedisty += g->r->deltadisty;
			g->r->mapy += g->r->stepy;
			g->r->side = 1;
		}
		if (g->c->map[g->r->mapx][g->r->mapy] == '1')
			which_wall(g);
	}
	if (g->r->side == 1 || g->r->side == 2)
		g->r->walldist = (g->r->mapx - g->c->pos_x +
			(1 - g->r->stepx) / 2) / g->r->raydirx;
	else if (g->r->side == 3 || g->r->side == 4)
		g->r->walldist = (g->r->mapy - g->c->pos_y +
			(1 - g->r->stepy) / 2) / g->r->raydiry;
}

void	sidedist(t_global *g)
{
	if (g->r->raydirx < 0)
	{
		g->r->stepx = -1;
		g->r->sidedistx = (g->c->pos_x - g->r->mapx) * g->r->deltadistx;
	}
	else
	{
		g->r->stepx = 1;
		g->r->sidedistx = (g->r->mapx + 1.0 - g->c->pos_x) * g->r->deltadistx;
	}
	if (g->r->raydiry < 0)
	{
		g->r->stepy = -1;
		g->r->sidedisty = (g->c->pos_y - g->r->mapy) * g->r->deltadisty;
	}
	else
	{
		g->r->stepy = 1;
		g->r->sidedisty = (g->r->mapy + 1.0 - g->c->pos_y) * g->r->deltadisty;
	}
}

void	init_var(t_global *g)
{
	g->r->camx = 2 * (double)g->r->screenx / (double)g->c->x - 1;
	g->r->raydirx = g->r->dirx + g->r->planx * g->r->camx;
	g->r->raydiry = g->r->diry + g->r->plany * g->r->camx;
	g->r->mapx = (int)g->c->pos_x;
	g->r->mapy = (int)g->c->pos_y;
	g->r->deltadistx = fabs(1 / g->r->raydirx);
	g->r->deltadisty = fabs(1 / g->r->raydiry);
	sidedist(g);
	walldist(g);
}

void	raycasting(t_global *g)
{
	int	i;

	i = 0;
	g->r->screenx = 0;
	while (g->r->screenx < g->c->x)
	{
		init_var(g);
		draw(g);
		g->s->buffer[g->r->screenx] = g->r->walldist;
		g->r->screenx++;
	}
	sprite(g);
}
