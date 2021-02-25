/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mathis <Mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:19:49 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/15 16:39:43 by Mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (size == 0)
		size = 1;
	if (count == 0 && size == 0)
		return (NULL);
	if (!(s = mmalloc(count * size)))
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
