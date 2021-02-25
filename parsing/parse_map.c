/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:01:31 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/19 15:11:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

int		line_length(char *line)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (line[i])
	{
		if (is_map_char(line[i]))
			length++;
		i++;
	}
	return (length);
}

char	*clean_line(char *line, t_global *g)
{
	char	*clean_line;
	int		length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = line_length(line) + 1;
	if (!(clean_line = mmalloc(sizeof(char) * length)))
		exit_error("problem with memory allocation in map parsing", g);
	while (line[i])
	{
		if (line[i] != ' ' && !is_map_char(line[i]))
			exit_error("Provide only ltters and nbers in map descrip bro!", g);
		if (is_map_char(line[i]))
			clean_line[j++] = line[i];
		i++;
	}
	clean_line[j] = '/';
	clean_line[length] = '\0';
	mfree(line);
	return (clean_line);
}

void	parse_map(int fd, t_global *g)
{
	char	*line;
	int		ret;
	int		mod;
	int		i;

	ret = 1;
	mod = 0;
	while (ret > 0)
	{
		i = 0;
		if ((ret = get_next_line(fd, &line)) == -1)
			exit_error("read .cub doesn't work bro", g);
		if ((line[0] == '1' || line[0] == '0' || line[0] == '2'
		|| line[0] == ' ') && mod != 1)
		{
			line = clean_line(line, g);
			g->c->map_1d = ft_strjoin(g->c->map_1d, line);
		}
		else if (mod == 1 && line[i] != '\0')
			exit_error("provide a proper .cub bro", g);
		else
			mod = 1;
	}
	g->c->tmp_map_2d = ft_split(g->c->map_1d, '/');
	mfree(line);
}
