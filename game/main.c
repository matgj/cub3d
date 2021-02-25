/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:57:46 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/21 15:37:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		file_name(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'b' && str[len - 1] == 'u' && str[len - 2] == 'c'
	&& str[len - 3] == '.')
		return (1);
	return (0);
}

int		save(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'e' && str[len - 1] == 'v' && str[len - 2] == 'a'
	&& str[len - 3] == 's' && str[len - 4] == '-' && str[len - 5] == '-')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_global	g;

	fd = 0;
	if (ac < 2)
		exit_begin("a .cub is missing bro", &g);
	if ((ac == 2 || ac == 3) && file_name(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		init_struct_ptr(&g);
		g.r->mlx_ptr = mlx_init();
		parse_info(fd, &g);
		g.r->win_ptr = mlx_new_window(g.r->mlx_ptr,
		g.c->x, g.c->y, "Cub3D");
		if (ac == 3 && save(av[2]))
			bmp(&g, g.c->x, g.c->y);
		hook(&g);
	}
	close(fd);
	return (0);
}
