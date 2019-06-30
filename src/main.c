/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:08:21 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/29 20:14:28 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** read a file line by line. If line is a room or a link, line is saved.
** if line is not good, stop read. Else (comment or ANT), keep read.
*/

int		ft_read_file(int fd, t_global *g)
{
	char	*line;
	int		ret_gnl;
	int		ret_chl;

	line = NULL;
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{
		ret_chl = ft_check_line(g, line);
		if (ret_chl == ROOMS)
		{
			//if (!ft_stock_room(g))
			//	break;
		}
		if (ret_chl == LINKS)
		{
			//if (!ft_stock_link(g))
			//	break;
		}
		if (ret_chl == STOP_READ)
		{
			ft_printf("line d Error is %s\n", line);
			if (g->input_mem[ANTS])
				ft_printf("ANTS ACTIVATED\n");
			if (g->input_mem[ROOMS])
				ft_printf("ROOMS ACTIVATED\n");
			break;
		}
		free(line);
	}
	if (line)
		free(line);
	return (ret_gnl);
}

/*
** g stands for the general structure
*/

int		main(int ac, char **av)
{
	int		fd;
	t_global	g;

	if (ac < 2)
		ft_error("Not enough arguments");
	if (ac > 2)
		ft_error("Too many arguments");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error ("Can't open the file");
	ft_init_global(&g);
	if (ft_read_file(fd, &g) == -1)
		ft_error("Problem with get_next_line");
	ft_free_g_tmp(&g);
	// if (!ft_sufficient_data(&g))
	// 	ft_error("Error");
	// ft_solver(&g);
	return (0);
}
