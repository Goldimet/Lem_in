/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:36:06 by agilmet           #+#    #+#             */
/*   Updated: 2019/07/25 15:36:08 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned long    ft_hash(char *str)
{
  unsigned long    hash;
  int                c;
  
  hash = 0;
  while ((c = *(str++)))
      hash = c + (hash << 6) + (hash << 16) - hash;
  return (hash);
}
