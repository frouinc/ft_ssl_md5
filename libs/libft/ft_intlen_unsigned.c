/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:14 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:38 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen_unsigned(unsigned int nbr)
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
