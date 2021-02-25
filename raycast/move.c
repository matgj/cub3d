/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:03:02 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/16 23:56:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward(t_global *g)
{
	if (g->c->map[(int)(g->c->pos_x + g->r->dirx * 0.6)]
	[(int)g->c->pos_y] != '1'
	&& g->c->map[(int)(g->c->pos_x + g->r->dirx * 0.6)]
	[(int)g->c->pos_y] != 'Z')
		g->c->pos_x += g->r->dirx * 0.6;
	if (g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y + g->r->diry * 0.6)] != '1'
	&& g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y + g->r->diry * 0.6)] != 'Z')
		g->c->pos_y += g->r->diry * 0.6;
}

void	backward(t_global *g)
{
	if (g->c->map[(int)(g->c->pos_x - g->r->dirx * 0.6)]
	[(int)g->c->pos_y] != '1'
	&& g->c->map[(int)(g->c->pos_x - g->r->dirx * 0.6)]
	[(int)g->c->pos_y] != '2')
		g->c->pos_x -= g->r->dirx * 0.6;
	if (g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y - g->r->diry * 0.6)] != '1'
	&& g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y - g->r->diry * 0.6)] != 'Z')
		g->c->pos_y -= g->r->diry * 0.6;
}

void	left(t_global *g)
{
	if (g->c->map[(int)(g->c->pos_x - g->r->planx * 0.6)]
	[(int)g->c->pos_y] != '1'
	&& g->c->map[(int)(g->c->pos_x - g->r->planx * 0.6)]
	[(int)g->c->pos_y] != 'Z')
		g->c->pos_x -= g->r->planx * 0.6;
	if (g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y - g->r->plany * 0.6)] != '1'
	&& g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y - g->r->plany * 0.6)] != 'Z')
		g->c->pos_y -= g->r->plany * 0.6;
}

void	right(t_global *g)
{
	if (g->c->map[(int)(g->c->pos_x + g->r->planx * 0.6)]
	[(int)g->c->pos_y] != '1'
	&& g->c->map[(int)(g->c->pos_x + g->r->planx * 0.6)]
	[(int)g->c->pos_y] != 'Z')
		g->c->pos_x += g->r->planx * 0.6;
	if (g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y + g->r->plany * 0.6)] != '1'
	&& g->c->map[(int)g->c->pos_x]
	[(int)(g->c->pos_y + g->r->plany * 0.6)] != 'Z')
		g->c->pos_y += g->r->plany * 0.6;
}

void	rotate(t_global *g, int key)
{
	double olddirx;
	double oldplanex;

	if (key == 65363)
	{
		olddirx = g->r->dirx;
		g->r->dirx = g->r->dirx * cos(-0.1) - g->r->diry * sin(-0.1);
		g->r->diry = olddirx * sin(-0.1) + g->r->diry * cos(-0.1);
		oldplanex = g->r->planx;
		g->r->planx = g->r->planx * cos(-0.1) - g->r->plany * sin(-0.1);
		g->r->plany = oldplanex * sin(-0.1) + g->r->plany * cos(-0.1);
	}
	if (key == 65361)
	{
		olddirx = g->r->dirx;
		g->r->dirx = g->r->dirx * cos(0.1) - g->r->diry * sin(0.1);
		g->r->diry = olddirx * sin(0.1) + g->r->diry * cos(0.1);
		oldplanex = g->r->planx;
		g->r->planx = g->r->planx * cos(0.1) - g->r->plany * sin(0.1);
		g->r->plany = oldplanex * sin(0.1) + g->r->plany * cos(0.1);
	}
}
