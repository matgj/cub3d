/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:59:10 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/17 12:42:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_start_end(t_global *g)
{
	if (g->s->drawstarty < 0)
		g->s->drawstarty = 0;
	g->s->drawendy = g->s->spriteheight / 2 + g->c->y / 2;
	if (g->s->drawendy >= g->c->y)
		g->s->drawendy = g->c->y - 1;
	g->s->spritewidth = abs((int)(g->c->y / (g->s->transformy)));
	g->s->drawstartx = -g->s->spritewidth / 2 + g->s->spritescreenx;
	if (g->s->drawstartx < 0)
		g->s->drawstartx = 0;
	g->s->drawendx = g->s->spritewidth / 2 + g->s->spritescreenx;
	if (g->s->drawendx >= g->c->x)
		g->s->drawendx = g->c->x - 1;
	g->s->stripe = g->s->drawstartx;
}

int		is_black(t_global *g, int y)
{
	if (g->i[5]->img_data[g->i[5]->sl *
	g->s->texy + g->s->texx * g->i[5]->bpp / 8] == 0
	&& g->i[5]->img_data[(g->i[5]->sl * g->s->texy +
	g->s->texx * g->i[5]->bpp / 8) + 1] == 0
	&& g->i[5]->img_data[(g->i[5]->sl * g->s->texy +
	g->s->texx * g->i[5]->bpp / 8) + 2] == 0)
		return (1);
	return (0);
}

void	draw_sprite(t_global *g, int y)
{
	g->i[0]->img_data[g->s->stripe
	* g->i[0]->bpp / 8 + g->i[0]->sl
	* y] = g->i[5]->img_data[g->i[5]->sl
	* g->s->texy + g->s->texx * g->i[5]->bpp / 8];
	g->i[0]->img_data[(g->s->stripe
	* g->i[0]->bpp / 8 + g->i[0]->sl
	* y) + 1] = g->i[5]->img_data[(g->i[5]->sl
	* g->s->texy + g->s->texx * g->i[5]->bpp / 8) + 1];
	g->i[0]->img_data[(g->s->stripe
	* g->i[0]->bpp / 8 + g->i[0]->sl
	* y) + 2] = g->i[5]->img_data[(g->i[5]->sl
	* g->s->texy + g->s->texx * g->i[5]->bpp / 8) + 2];
}

void	ray_sprite(t_global *g)
{
	int	y;

	while (g->s->stripe < g->s->drawendx)
	{
		g->s->texx = (int)(256 * (g->s->stripe - (-g->s->spritewidth / 2 +
		g->s->spritescreenx)) * g->i[5]->width / g->s->spritewidth) / 256;
		if (g->s->transformy > 0 && g->s->stripe > 0 && g->s->stripe
		< g->c->x && g->s->transformy < g->s->buffer[g->s->stripe])
		{
			y = g->s->drawstarty;
			while (y < g->s->drawendy)
			{
				g->s->d = y * 256 - g->c->y * 128 + g->s->spriteheight * 128;
				g->s->texy = ((g->s->d * g->i[5]->height) / g->s->spriteheight)
				/ 256;
				if (!is_black(g, y))
					draw_sprite(g, y);
				y++;
			}
		}
		g->s->stripe++;
	}
}

void	sprite(t_global *g)
{
	int	i;

	i = 0;
	sort_sprites(g);
	while (i < g->s->nb_sprite)
	{
		g->s->spritex = (g->z[i]->x - g->c->pos_x) + 0.5;
		g->s->spritey = (g->z[i]->y - g->c->pos_y) + 0.5;
		g->s->invdet = 1.0 / (g->r->planx * g->r->diry - g->r->dirx *
		g->r->plany);
		g->s->transformx = g->s->invdet * (g->r->diry * g->s->spritex -
		g->r->dirx * g->s->spritey);
		g->s->transformy = g->s->invdet * (-g->r->plany *
		g->s->spritex + g->r->planx * g->s->spritey);
		g->s->spritescreenx = (int)((g->c->x / 2) *
		(1 + g->s->transformx / g->s->transformy));
		g->s->spriteheight = abs((int)(g->c->y / (g->s->transformy)));
		g->s->drawstarty = -g->s->spriteheight / 2 + g->c->y / 2;
		sprite_start_end(g);
		ray_sprite(g);
		i++;
	}
}
