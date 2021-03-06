/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mathis <Mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:40:06 by magrosje          #+#    #+#             */
/*   Updated: 2020/04/15 16:39:43 by Mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_str_line(char const *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(str = (char*)mmalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[j] != '\0' && s[j] != c)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		ft_cpt_words(char const *s, char c)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	char	**tab;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)mmalloc(sizeof(char *) * (ft_cpt_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			tab[l] = ft_str_line(&s[i], c);
			l++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	tab[l] = NULL;
	return (tab);
}
