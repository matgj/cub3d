/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:42:16 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/21 15:36:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player(t_global *g, int x, int y)
{
	if (g->c->map[x][y] == 'N')
	{
		g->r->plany = 0.66;
		g->r->dirx = -1;
	}
	else if (g->c->map[x][y] == 'S')
	{
		g->r->plany = -0.66;
		g->r->dirx = 1;
	}
	else if (g->c->map[x][y] == 'W')
	{
		g->r->planx = -0.66;
		g->r->diry = -1;
	}
	else if (g->c->map[x][y] == 'E')
	{
		g->r->planx = 0.66;
		g->r->diry = 1;
	}
}

int		key_management(int key, t_global *g)
{
	if (key == 65307)
		close_win(g);
	else if (key == 119)
		forward(g);
	else if (key == 115)
		backward(g);
	else if (key == 97)
		left(g);
	else if (key == 100)
		right(g);
	else if (key == 65363)
		rotate(g, key);
	else if (key == 65361)
		rotate(g, key);
	return (0);
}

int		raycast_image(t_global *g)
{
	int endian;

	if (g->i[0]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[0]->img_ptr);
	g->i[0]->img_ptr = mlx_new_image(g->r->mlx_ptr, g->c->x, g->c->y);
	g->i[0]->img_data = mlx_get_data_addr(g->i[0]->img_ptr, &g->i[0]->bpp,
		&g->i[0]->sl, &endian);
	raycasting(g);
	mlx_put_image_to_window(g->r->mlx_ptr, g->r->win_ptr,
		g->i[0]->img_ptr, 0, 0);
	return (0);
}

void	hook(t_global *g)
{
	mlx_hook(g->r->win_ptr, 2, 1L << 0, key_management, g);
	mlx_hook(g->r->win_ptr, 33, 1L << 17, red_x, (void*)0);
	mlx_loop_hook(g->r->mlx_ptr, raycast_image, g);
	mlx_loop(g->r->mlx_ptr);
}
