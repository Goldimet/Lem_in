/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:47:03 by agilmet           #+#    #+#             */
/*   Updated: 2019/06/30 17:47:12 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_free_g_tmp(t_global *g)
{
    if (g->tmp_link_r1)
        free(g->tmp_link_r1);
    if (g->tmp_link_r2)
        free(g->tmp_link_r2);
    if (g->tmp_room)
        free(g->tmp_room);
}