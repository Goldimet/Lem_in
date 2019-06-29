/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:41:20 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/29 16:05:56 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_init_global(t_global *g)
{
    int i;

    i = 0;
    g->size = 0;
    g->nb_ants = 0;
    while (i < INPUT_MEM)
        g->input_mem[i++] = 0;
    g->start = NULL;
    g->end = NULL;
    g->tab = NULL;
}