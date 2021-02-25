/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:02:39 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/22 12:36:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error(char *str, t_global *g)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	if (g->i[0]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[0]->img_ptr);
	if (g->i[1]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[1]->img_ptr);
	if (g->i[2]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[2]->img_ptr);
	if (g->i[3]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[3]->img_ptr);
	if (g->i[4]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[4]->img_ptr);
	if (g->i[5]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[5]->img_ptr);
	if (g->r->mlx_ptr)
		free(g->r->mlx_ptr);
	free_all_malloc();
	exit(EXIT_FAILURE);
}

int		close_win(t_global *g)
{
	if (g->r->win_ptr)
		mlx_destroy_window(g->r->mlx_ptr, g->r->win_ptr);
	if (g->i[0]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[0]->img_ptr);
	if (g->i[1]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[1]->img_ptr);
	if (g->i[2]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[2]->img_ptr);
	if (g->i[3]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[3]->img_ptr);
	if (g->i[4]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[4]->img_ptr);
	if (g->i[5]->img_ptr)
		mlx_destroy_image(g->r->mlx_ptr, g->i[5]->img_ptr);
	free_all_malloc();
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_begin(char *str, t_global *g)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	free_all_malloc();
	exit(EXIT_FAILURE);
}

int		red_x(t_global *g)
{
	exit(EXIT_SUCCESS);
}
