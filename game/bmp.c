/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:20:10 by Mathis            #+#    #+#             */
/*   Updated: 2020/04/17 12:33:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_bmp(char **data, t_global *g)
{
	int i;
	int j;
	int x;
	int y;

	i = 122;
	y = g->c->y;
	while (y--)
	{
		x = -1;
		while (++x < g->c->x)
		{
			j = (x * (g->i[0]->bpp / 8)) + (y * g->i[0]->sl);
			*(*data + i++) = *((char *)g->i[0]->img_data + j++);
			*(*data + i++) = *((char *)g->i[0]->img_data + j++);
			*(*data + i++) = *((char *)g->i[0]->img_data + j);
		}
	}
}

void	header_bmp(char **data, t_global *g)
{
	unsigned int size;

	size = g->c->y * g->c->x * 3;
	*(unsigned short *)*data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*data + 2) = (size + 122);
	*(unsigned int *)(*data + 6) = 0u;
	*(unsigned char *)(*data + 10) = 122;
	*(unsigned int *)(*data + 14) = 122 - 14;
	*(unsigned int *)(*data + 18) = g->c->x;
	*(unsigned int *)(*data + 22) = g->c->y;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = (unsigned int)size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

void	bmp(t_global *g, int w, int h)
{
	int				fd;
	unsigned int	i;
	char			*data;

	i = 0;
	if (!(data = mmalloc((w * h * 3 + 122))))
		exit_error("problem with memory allocation bro", g);
	write(1, "\033[1;36mCreating image... \033[0m", 29);
	raycast_image(g);
	while (i < w * h * 3 + 122)
		data[i++] = 0;
	header_bmp(&data, g);
	fill_bmp(&data, g);
	if ((fd = open("zzz.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
		exit_error("creation of .bmp failed bro", g);
	write(fd, data, (w * h * 3 + 122));
	close(fd);
	write(1, "\033[1;36mdone!\n\033[0m", 17);
	exit(0);
}
