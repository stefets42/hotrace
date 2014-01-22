/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:47:19 by grebett           #+#    #+#             */
/*   Updated: 2013/12/14 22:04:52 by sdesnogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;
	size_t	i;

	size = ft_strlen((char *) s1);
	s2 = (char *) malloc(sizeof(char) * size + 1);
	if (s2 != NULL)
	{
		i = 0;
		while (i < size)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
