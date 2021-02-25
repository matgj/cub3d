/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mathis <Mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:38:27 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/15 16:39:43 by Mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	if (src < dst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		}
	}
	else
	{
		if ((dst == 0) && (src == 0))
			return (0);
		i = 0;
		while (i < n)
		{
			((unsigned char*)dst)[i] = ((unsigned const char*)src)[i];
			i++;
		}
	}
	return (dst);
}
