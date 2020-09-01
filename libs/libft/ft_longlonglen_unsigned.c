/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:31 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:33 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_longlonglen_unsigned(unsigned long long nbr)
{
	int		count;

	count = 1;
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
