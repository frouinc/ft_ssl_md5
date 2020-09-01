/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_longlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:43:14 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:23 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_putnbr_longlong(long long nb)
{
	if (nb < -9223372036854775807)
	{
		if (ft_putnbr_longlong((nb / 10) * -1) == -1)
			return (-1);
		return (ft_putchar(((nb % 10) * -1) + '0'));
	}
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = nb * -1;
	}
	if (nb >= 10)
		if (ft_putnbr_longlong(nb / 10) == -1)
			return (-1);
	return (ft_putchar(nb % 10 + '0'));
}
