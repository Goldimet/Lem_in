/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/10/08 12:52:43 by rkamegne          #+#    #+#             */
/*   Updated: 2019/07/01 13:14:35 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
=======
/*   Created: 2018/10/08 22:09:27 by agilmet           #+#    #+#             */
/*   Updated: 2019/04/23 10:53:36 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WHAT IT DOES
**    locates first occurence of "c" in "s". Remarque : locates \0  si c = \0
**
** RETURN
**    pointer to located char, or NULL si pas trouve.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == (const char)c)
			return ((char*)s);
		s++;
>>>>>>> 597a5570f102951413075b0a1d6dded7794bf5cb
	}
	if (*s == (const char)c)
		return ((char*)s);
	else
		return (0);
}
