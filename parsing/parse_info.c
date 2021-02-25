/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:15 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/20 14:50:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct_ptr(t_global *g)
{
	int	j;

	j = 0;
	if (!(g->c = mmalloc(sizeof(t_config))))
		exit_error("problem with memory allocation in structures creation", g);
	ft_bzero(g->c, sizeof(t_config));
	if (!(g->r = mmalloc(sizeof(t_ray))))
		exit_error("problem with memory allocation in structures creation", g);
	ft_bzero(g->r, sizeof(t_ray));
	if (!(g->s = mmalloc(sizeof(t_sprite))))
		exit_error("problem with memory allocation in structures creation", g);
	ft_bzero(g->s, sizeof(t_sprite));
	if (!(g->i = mmalloc(sizeof(t_image *) * 7)))
		exit_error("problem with memory allocation in structures creation", g);
	ft_bzero(g->i, sizeof(t_image *) * 7);
	while (j <= 5)
	{
		if (!(g->i[j] = mmalloc(sizeof(t_image))))
			exit_error("problem with memory alloc in structures creation", g);
		ft_bzero(g->i[j], sizeof(t_image));
		j++;
	}
}

void	sort_infos(char *line, t_global *g)
{
	if (line[0] == '\0')
		return ;
	else if (line[0] == 'R')
		parse_res((line + 1), g);
	else if (line[0] == 'N' && line[1] == 'O')
		parse_textures((line + 2), g, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_textures((line + 2), g, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_textures((line + 2), g, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_textures((line + 2), g, 4);
	else if (line[0] == 'S' && line[1] != 'O')
		parse_textures((line + 1), g, 5);
	else if (line[0] == 'F')
		parse_ray_floor((line + 1), g);
	else if (line[0] == 'C')
		parse_ray_ceiling((line + 1), g);
	else
		exit_error("Put classic stuff in .cub as indicated in the subject!", g);
}

void	map_verif(t_global *g)
{
	if (g->c->map_1d)
		create_map(g);
	else
		exit_error("Provide a map bro!", g);
}

void	parse_info(int fd, t_global *g)
{
	char	*line;
	int		ret;
	int		i;

	ret = 1;
	while (ret > 0)
	{
		i = 0;
		if ((ret = get_next_line(fd, &line)) == -1)
			exit_error("read .cub doesn't work bro", g);
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
			break ;
		sort_infos(&line[i], g);
	}
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
	{
		line = clean_line(line, g);
		g->c->map_1d = ft_strjoin(g->c->map_1d, line);
		parse_map(fd, g);
	}
	mfree(line);
	map_verif(g);
}
