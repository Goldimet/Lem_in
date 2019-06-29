/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:48:06 by rkamegne          #+#    #+#             */
/*   Updated: 2019/04/18 14:50:33 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_nb_len(unsigned long long n, int base)
{
	int				i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

long long			ft_abs(long long n)
{
	return ((n < 0) ? -n : n);
}

char				*ft_itoa(long long n)
{
	char	*str;
	char	*temp;

	temp = ft_utoa(ft_abs(n));
	if (n < 0)
	{
		str = ft_strjoin("-", temp);
		ft_strdel(&temp);
		return (str);
	}
	return (temp);
}

char				*ft_utoa(unsigned long long n)
{
	char			*str;
	int				len;

	len = ft_nb_len(n, 10);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (--len > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = n + '0';
	return (str);
}
