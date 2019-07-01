/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:58:20 by agilmet           #+#    #+#             */
/*   Updated: 2019/06/30 17:33:25 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WHAT IT DOES
**   The atoi() function converts the initial portion of the string
**   pointed to by str to int representation
*/
#include "libft.h"

long long	ft_atollong(const char *str)
{
	long long n;
	long long sign;
	long long i;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
	|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (n && sign == 1 && (n ^ ((n * 10) + (str[i] - 48))) < 0)
			return (-1);
		if (n && sign == -1 && (n ^ ((n * 10) + (str[i] - 48))) < 0)
			return (0);
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (sign * n);
}
/*
**int main()
**{
**	char s[] = "\t\v\f\r\n \f-06050";
**	char *s2 = NULL;
**	char s3[] = "999999999999999999999";
**	char s4[] = "-poui";
**	char s5[] = "-34poui";
**
**	printf("libc s: %d\n", atoi(s));
**	printf("le mien s: %d\n", ft_atoi(s));
**	printf("libc s2: %d\n", atoi(s2));
**	printf("le mien s2: %d\n", ft_atoi(s2));
**	printf("libc s3: %d\n", atoi(s3));
**	printf("le mien s3: %d\n", ft_atoi(s3));
**	printf("libc s4: %d\n", atoi(s4));
**	printf("le mien s4: %d\n", ft_atoi(s4));
**	printf("libc s5: %d\n", atoi(s5));
**	printf("le mien s5: %d\n", ft_atoi(s5));
**	return (0);
**}
*/
