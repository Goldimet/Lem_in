/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:45:34 by rkamegne          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/29 21:14:50 by rkamegne         ###   ########.fr       */
=======
/*   Updated: 2019/06/30 17:33:18 by agilmet          ###   ########.fr       */
>>>>>>> 597a5570f102951413075b0a1d6dded7794bf5cb
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		is_negative;
	int		nbr;

	i = 0;
	is_negative = 0;
	nbr = 0;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (is_negative)
		nbr = -nbr;
	return (nbr);
}
