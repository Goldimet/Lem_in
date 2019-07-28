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

# define NODE_ARR_SIZE 50
/*
** Indexes to g->input_order, INPUT_ORDER_SIZE est le nombre d indexes
*/
# define ANTS 0
# define ROOMS 1
# define LINKS 2
# define START 3
# define END 4
# define INPUT_ORDER_SIZE 5

/* 
** Return values of ft_check_line + les define precedents pour ROOM et LINK
*/

# define SKIP 0
# define STOP_READ -1

/*
 * STRUCT ROOM
 */

typedef	struct	s_rooom
{
	char				*name;
	struct s_links		*links;
	struct s_room		*next;
}				t_room;

/*
 * STRUCT LINK
 */

typedef	struct	s_links
{
	t_room				*node;
	t_room				*next;
}				t_links;


/*
 *  STRUCT GENERAL
 */

typedef	struct	s_global
{
	int		nb_ants;
	char	input_order[INPUT_ORDER_SIZE];
	t_room	*node_arr[NODE_ARR_SIZE];
	t_room	*start;
	t_room	*end;
	char	*tmp_node;
	char	*tmp_link_n1;
	char	*tmp_link_n2;
	
}				t_global;

//void			ft_init_global(t_global *g);
int				ft_check_if_int(char *str, char stop);
int				ft_check_line(t_global *g, char *line);
void			ft_free_g_tmp(t_global *g);
unsigned long	ft_hash(char *str);
int				ft_stock_room(t_global *g);



#endif

#define UNIDIR1 1
#define UNIDIR2 2
#define BIDIR  UNIDIR1 + UNIDIR2


typedef struct s_room_link
{
	t_room		*node;
	t_room_link *next;
}				t_room_link;

typedef struct s_room
{
	char		*name;
	int			hash;
	t_edge		**edge;
	int			nb_edge;
	...
}				t_room;

typedef struct s_edge
{
	t_room	*node1;
	t_room	*node2;
	int		dir;
	int		w1;
	int		w2;
}				t_edge;