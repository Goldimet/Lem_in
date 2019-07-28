/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:00:55 by agilmet           #+#    #+#             */
/*   Updated: 2019/07/25 15:00:58 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int     ft_push_node(t_global *g, unsigned long index, t_room *node)
{
    t_room *tmp;

    tmp = g->node_arr[index];
    while (tmp->next)
    {
        if (ft_strequ(tmp->name, node->name))
            return(0)
        tmp = tmp->next;
    }
    tmp->next = node;
}

int     ft_stock_room(t_global *g)
{
    unsigned long   index;
    t_room          *node;

    if (!(node = ft_memalloc(sizeof(t_room))))
        exit(0);
    if (!(node->name = ft_strdup(g->tmp_node)))
        exit(0);
    ft_memdel(&g->tmp_node);
    index = ft_hash(g->tmp_node) % NODE_ARR_SIZE;
    if (!g->node_arr[index])
        g->node_arr[index] = node;
    else
    {
        if (!ft_push_node(g, index, node))
            return (0);
    } 
    if (g->input_order[START] == 1 || g->input_order[END] == 1)
        ft_put_start_end(g, node);
    return (1);
       
    while (g->node_arr[index])

    
}