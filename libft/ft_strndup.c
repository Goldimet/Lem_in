/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:13:02 by agilmet           #+#    #+#             */
/*   Updated: 2019/06/30 17:33:37 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(char) * (n + 1));
	if (s2 == NULL || n > i)
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
**int main()
**{
**	char s1[] = "qwerty";
**	printf("%s\n", ft_strndup(s1, 0));
**	return (0);
**}
*/
