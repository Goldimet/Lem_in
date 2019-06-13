/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:41:33 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/10 14:14:11 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	int		count;
	int		boolean;

	count = 0;
	boolean = 0;
	while (*s)
	{
		if (*s == c && boolean == 1)
			boolean = 0;
		if (*s != c && boolean == 0)
		{
			count++;
			boolean = 1;
		}
		s++;
	}
	return (count);
}
