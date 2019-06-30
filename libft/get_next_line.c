/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:56:33 by agilmet           #+#    #+#             */
/*   Updated: 2019/05/01 18:50:34 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_save_buf(char **str, char *buf)
{
	char	*tmp;

	if (!(*str))
	{
		if ((*str = ft_strdup(buf)) == NULL)
			return (0);
	}
	else
	{
		tmp = *str;
		if ((*str = ft_strjoin(*str, buf)) == NULL)
		{
			ft_strdel(str);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

int		ft_fill_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (((*line = ft_strndup(*str, i)) == NULL) ||
	((*str)[i] && ((tmp = ft_strdup((*str) + i + 1)) == NULL)))
	{
		ft_strdel(str);
		if ((*line))
			ft_strdel(line);
		return (0);
	}
	if (!(*str)[i])
	{
		ft_strdel(str);
		return (1);
	}
	free(*str);
	*str = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *tab[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	ret = 1;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	while (!(ft_strchr(tab[fd] + i, '\n')) && (i += ret - 1) >= 0 && ret)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (!ft_save_buf(tab + fd, buf))
			return (-1);
	}
	if (!ft_fill_line(&(tab[fd]), line))
		return (-1);
	if (!ret && !**line)
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}
