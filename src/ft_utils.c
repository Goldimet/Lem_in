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
    g->tmp_room = NULL;
    g->tmp_link_r1 = NULL;
    g->tmp_link_r2 = NULL;
    g->start = NULL;
    g->end = NULL;
    g->tab = NULL;
}

/*
** Check if str est bien un INT avant d arriver sur caractere stop.
*/

int     ft_check_if_int(char *str, char stop)
{
    int i;
    int nb;

    i = 0;
    if (*str == '+' || *str == '-')
        str++;
    if (!ft_isdigit(*str))
        return (0);
    while (*str == '0')
        str++;
    while (str[i] && str[i] != stop)
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    if (str[i] != stop)
        return (0);
    nb = ft_atollong(str);
	if (i > 10 || nb > INT_MAX)
        return (0);
    return (1);
}