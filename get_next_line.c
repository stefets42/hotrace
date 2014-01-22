/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:30:19 by grebett           #+#    #+#             */
/*   Updated: 2013/12/15 13:00:34 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	split_buf(char **line, char **buf, char **str)
{
	int		i;
	char	*strp;
	char	*bufp;
	char	*tmp;

	strp = *str;
	bufp = *buf;
	i = 0;
	while ((bufp[i] != '\0') && (bufp[i] != '\n'))
		i++;
	tmp = ft_strsub(bufp, 0, i);
	strp = ft_strjoin(strp, tmp);
	*buf = ft_strsub(bufp, i + 1, BUFF_SIZE - i);
	if (bufp[i] == '\n')
	{
		*line = strp;
		free(strp);
		return (1);
	}
	*str = strp;
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	static char	flag = 0;
	char		*str;
	int			ret;

	str = ft_strnew(1);
	if (buf != NULL)
	{
		if (split_buf(line, &buf, &str))
			return (1);
	}
	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (split_buf(line, &buf, &str))
			return (1);
	}
	if ((ft_strlen(str)) && (flag == 0))
	{
		*line = str;
		flag++;
		return (1);
	}
	return (ret);
}
