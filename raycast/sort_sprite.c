/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:42:08 by user42            #+#    #+#             */
/*   Updated: 2020/04/17 12:44:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sort_sprites(t_global *g)
{
	int			i;
	t_z_sprite	*swap;

	i = 0;
	while (i < g->s->nb_sprite)
	{
		g->z[i]->s_dist = ((g->c->pos_x - g->z[i]->x) * (g->c->pos_x -
		g->z[i]->x) + (g->c->pos_y - g->z[i]->y) * (g->c->pos_y - g->z[i]->y));
		i++;
	}
	i = 0;
	while (i < g->s->nb_sprite)
	{
		if (g->z[i]->s_dist < g->z[i + 1]->s_dist && (i + 1) < g->s->nb_sprite)
		{
			swap = g->z[i];
			g->z[i] = g->z[i + 1];
			g->z[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}
