/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:01:31 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/17 12:17:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_size(t_global *g)
{
	int	x;
	int y;

	x = 0;
	while (g->c->tmp_map_2d[x])
	{
		y = 0;
		while (g->c->tmp_map_2d[x][y])
			y++;
		if (y > g->c->max_y)
			g->c->max_y = y;
		x++;
	}
	g->c->max_x = x;
}

void	init_map(t_global *g)
{
	int	x;
	int	y;

	x = 0;
	map_size(g);
	if (!(g->c->map = mmalloc(sizeof(char *) * (g->c->max_x + 2))))
		exit_error("problem with memory allocation in init_map bro", g);
	g->c->map[g->c->max_x + 1] = 0;
	while (x <= g->c->max_x)
	{
		y = 0;
		if (!(g->c->map[x] = mmalloc(sizeof(char) * (g->c->max_y + 2))))
			exit_error("problem with memory allocation in init_map bro", g);
		while (y < g->c->max_y)
		{
			g->c->map[x][y] = '/';
			y++;
		}
		g->c->map[x][g->c->max_y] = '\0';
		x++;
	}
}

void	fill_map(t_global *g)
{
	int	x;
	int	y;
	int	player;

	x = -1;
	player = 0;
	while (++x < g->c->max_x)
	{
		y = 0;
		while (g->c->tmp_map_2d[x][y])
		{
			g->c->map[x][y] = g->c->tmp_map_2d[x][y];
			if (g->c->tmp_map_2d[x][y] == 'N' || g->c->tmp_map_2d[x][y] == 'S'
			|| g->c->tmp_map_2d[x][y] == 'W' || g->c->tmp_map_2d[x][y] == 'E')
			{
				g->c->pos_x = (double)x + 0.5;
				g->c->pos_y = (double)y + 0.5;
				player++;
			}
			y++;
		}
	}
	if (player != 1)
		exit_error("Please provide one player bro, ONLY one !",
		g);
}

void	check_map(t_global *g, int x, int y)
{
	if (g->c->map[x][y] == '1' || g->c->map[x][y] == 'O'
		|| g->c->map[x][y] == 'Z')
		return ;
	if (x == 0 || y == 0 || g->c->map[x][y] == '/'
		|| g->c->map[x][y] == '\0' || g->c->map[x][y] == ' ')
		exit_error("close the map around the player start pos bro :)",
		g);
	if (g->c->map[x][y] == '0')
		g->c->map[x][y] = 'O';
	else if (g->c->map[x][y] == '2')
	{
		g->c->map[x][y] = 'Z';
		g->s->nb_sprite++;
	}
	check_map(g, x + 1, y);
	check_map(g, x, y + 1);
	check_map(g, x - 1, y);
	check_map(g, x, y - 1);
}

void	create_map(t_global *g)
{
	g->cpt++;
	if (!g->c->x || !g->c->y || !g->c->north || !g->c->south || !g->c->west
	|| !g->c->east || !g->c->sprite)
		exit_error("some infos are missing in the .cub bro", g);
	init_map(g);
	fill_map(g);
	set_player(g, (int)g->c->pos_x, (int)g->c->pos_y);
	check_map(g, (int)g->c->pos_x, (int)g->c->pos_y);
	init_sprite(g);
}
