/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:29:06 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/30 00:11:04 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_is_room(t_global *g, char *line)
{
	int i;

	i = 0;
	if (*line == 'l' || *line == 'L')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i++] != ' ')
		return (0);
	while (line[i] && line[i] != ' ')
		if (!ft_isidigit(line[i++])
			return(0);
	if (line[i++] != ' ')
		return (0);
	while (line[i])
		if (!ft_isidigit(line[i++])
			return(0);
	return (1);
}

/*
**	WHAT IT DOES
** Check if line est bien un INT > 0
** Si oui, remplit g->nb_ants, sinon ft_error 
*/

int		ft_is_ants(t_global *g, char *line)
{
	int i;
	long long nb;

	i = 0;
	while (line[i++])
	{
		if (!ft_isdigit(*line))
			ft_error("No valid ant number in the begining");
	}
	nb = ft_atollong(line);
	if (i > 10 || nb <= 0 || nb > INT_MAX)
		ft_error("No valid ant number");
	g->nb_ants = (int)nb;
	return (1);
}

int		ft_check_line(t_global *g, char *line)
{
	if (!line || !(*line))
		return (-1);
	if (*line == '#')
	{
		if (line == "##start")
			g->input_mem[START] = 1;
		else if (line == "##end")
			g->input_mem[END] = 1;
		return (100);
	}
	if (!g->input_mem[ANTS])
	{
		ft_is_ants(g, line)
		g->input_mem[ANTS] = 1;
		return (ANTS);
	}
	if (!g->input_mem[ROOMS])
		if (ft_is_room(line, g))
			return (ROOMS);
	if (g->input_mem[START] == 1 || g->input_mem[END] == 1)
		return (-1);
	g->input_mem[ROOMS] = 1;
	if (ft_is_link(line))
		return (LINKS);
	return (-1);
}
