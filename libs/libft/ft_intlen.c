/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:58:06 by cfrouin          #+#    #+#             */
/*   Updated: 2017/06/07 16:07:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen(int nbr)
{
	int		count;

	count = 1;
	if (nbr < 0)
	{
		++count;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
