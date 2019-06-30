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

/*
**	WHAT IT DOES
** Check if line est bien un Link. Return 1 si oui, 0 sinon.
** Les deux rooms sont stored dans tmp_link_r1 et r2 pour ft_stock_link.
*/

static int		ft_is_link(t_global *g, char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	g->tmp_link_r1 = ft_strndup(line, i);
	if (!line[i++])
		return (0);
	if (!line[i])
		return (0);
	g->tmp_link_r2 = ft_strdup(line + i);
	return (1);
}

/*
**	WHAT IT DOES
** Check if line est bien une Room. Return 1 si oui, 0 sinon.
** Name of Room is stored in g->tmp_room pour ft_stock_room.
*/

static int		ft_is_room(t_global *g, char *line)
{
	int i;

	ft_printf("line de ft_room = %s\n", line);
	i = 0;
	if (*line == 'l' || *line == 'L')
		return (0);
	while (line[i] && line[i] != ' ')
	{
		if (line[i++] == '-')
			return(0);
	}
	g->tmp_room = ft_strndup(line, i);
	if (line[i++] != ' ')
		return (0);
	if (!ft_check_if_int(line + i, ' '))
		return (0);
	while (line[i] != ' ')
		i++;
	if (!ft_check_if_int(line + i + 1, '\0'))
		return(0);
	return (1);
}

/*
**	WHAT IT DOES
** Check if line est bien un INT > 0
** Si oui, remplit g->nb_ants, sinon ft_error 
*/

static	int		ft_is_ants(t_global *g, char *line)
{
	int nb;

	if (!ft_check_if_int(line, '\0'))
		ft_error("ERROR ant 1");
	nb = ft_atoi(line);
	if (nb <= 0)
		ft_error("ERROR ant 2");		
	g->nb_ants = nb;
	return (1);
}

/* 
** Continuite de ft_check_line ci-dessous. Check ordre ANT, ROOM, LINK. 
** Si ANT -> check que number est valide et stocke ant_nb dans struct g.
** SI ROOM -> check que valide format ROOM
** SI LINK -> check que valide format Link
*/

static int		ft_check_line_bis(t_global *g, char *line)
{
	if (!g->input_mem[ANTS])
	{
		ft_is_ants(g, line);
		g->input_mem[ANTS] = 1;
		return (SKIP);
	}
	if (!g->input_mem[ROOMS])
	{
		if (ft_is_room(g, line))
			return (ROOMS);
	}
	g->input_mem[ROOMS] = 1;
	if (ft_is_link(g, line))
		return (LINKS);
	return (STOP_READ);
}

/*
**	WHAT IT DOES
** -> Si START ou END est init, il faut absolument que la ligne soit un comment,
** command ou room valide. Sinon error.
** -> Skip les comments et command invalides, si START ou END, init START END
** -> Check le reste avec ft_check_line_bis
*/

int				ft_check_line(t_global *g, char *line)
{
	if ((g->input_mem[START] == 1 || g->input_mem[END] == 1) && *line != '#')
	{
		if (g->input_mem[ROOMS] || !g->input_mem[ANTS])
			ft_error("ERROR input[ROOMS ou ANT]");
		if (!ft_is_room(g, line))
				ft_error("ERROR pas Room start end");
		return (ROOMS);
	}
	if (*line == '#')
	{
		if (ft_strequ(line, "##start"))
		{
			if (g->start)
				return (STOP_READ);
			g->input_mem[START] = 1;
		}
		else if (ft_strequ(line, "##end"))
		{
			if (g->end)
				return (STOP_READ);
			g->input_mem[END] = 1;
		}
		return (SKIP);
	}
	return (ft_check_line_bis(g, line));	
}