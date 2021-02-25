/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:47:59 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/16 23:39:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pos_sprite(t_global *g)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (g->c->map[x])
	{
		y = 0;
		while (g->c->map[x][y] != '\0')
		{
			if (g->c->map[x][y] == 'Z')
			{
				g->z[i]->x = x;
				g->z[i]->y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	init_sprite(t_global *g)
{
	int	x;

	x = 0;
	if (!(g->z = mmalloc(sizeof(t_z_sprite *) * (g->s->nb_sprite + 1))))
		exit_error("problem with memory allocation in sprites init bro", g);
	ft_bzero(g->z, sizeof(t_z_sprite *) * (g->s->nb_sprite + 1));
	while (x <= g->s->nb_sprite)
	{
		if (!(g->z[x] = mmalloc(sizeof(t_z_sprite))))
			exit_error("problem with memory allocation in sprites init bro", g);
		ft_bzero(g->z[x++], sizeof(t_z_sprite));
	}
	pos_sprite(g);
}
