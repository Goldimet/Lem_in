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

/*
 * STRUCT LINK
 */

typedef	struct	s_link
{
	t_room			*r1;
	t_room			*r2;
}				t_link;

/*
 * STRUCT ROOM
 */

typedef	struct	s_room
{
	char		*name;
	t_link		*link;
	t_room		*next;
}				t_room;

/*
 *  STRUCT GENERAL
 */

typedef	struct	s_global
{
	int		nb_ants;
	int		size;
	t_room	**tab;
	t_room	*start;
	t_room	*end;
}				t_global;

void			ft_init(t_global *g);

#endif
