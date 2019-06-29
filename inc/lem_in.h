/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:09:25 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/29 19:09:38 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>

# define ANTS 0
# define ROOMS 1
# define LINKS 2
# define START 3
# define END 4
# define INPUT_MEM 5	

/*
 * STRUCT ROOM
 */

typedef	struct	s_room
{
	char		*name;
	struct s_link		*link;
	struct s_room		*next;
}				t_room;

/*
 * STRUCT LINK
 */

typedef	struct	s_link
{
	t_room			*r1;
	t_room			*r2;
}				t_link;

/*
 *  STRUCT GENERAL
 * 
 */

typedef	struct	s_global
{
	int		nb_ants;
	int		size;
	char	input_mem[INPUT_MEM];
	t_room	**tab;
	t_room	*start;
	t_room	*end;
}				t_global;

void			ft_init_global(t_global *g);
int				ft_check_line(char *line);

#endif
