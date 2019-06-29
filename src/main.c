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

// static	int		check_integer(char *str, int *num)
// {
// 	int		sign;
// 	int		len;

// 	*num = ft_atoi(str);
// 	if ((sign = *str == '-'))
// 		str++;
// 	if (!ft_isnumber(str))
// 		return (0);
// 	while (*str == '0')
// 		str++;
// 	len = ft_strlen(str);
// 	if (len > 10 || (len == 10 && *str > '2'))
// 		return (0);
// 	return (!((sign && *num > 0) || (!sign && *num < 0)));
// }

/*
** read inside a file and fill informations
*/

int		ft_read_file(int fd, t_global *g)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((ft_check_line(line, g)) == ROOMS)
			ft_stock_room(g, line);
		else if ((ft_check_line(line, g)) == LINKS)
			ft_stock_link(g, line);
		else if (ft_check_line(line, g) == -1)
		{
			free(line);
			return(0);
		}
		free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
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
	if (!ft_read_file(fd, &g))
		ft_error("Problem with get_next_line");
	if (!ft_sufficient_data(&g))
		ft_error("Error");
	ft_solver(&g);
	return (0);
}
