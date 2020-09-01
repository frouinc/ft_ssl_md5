/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:57 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:26 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_pow(double x, double y)
{
	double		res;

	if (y == 0.00)
		return (1);
	if (y < 0)
		return (1 / (ft_pow(x, (y * -1))));
	if (y == 1.00)
		return (x);
	res = x;
	while (--y > 0)
	{
		res = res * x;
	}
	return (res);
}
