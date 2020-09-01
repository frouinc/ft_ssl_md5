/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:12:25 by cfrouin           #+#    #+#             */
/*   Updated: 2020/09/01 11:17:17 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			print_hash(const uint8_t hash[32], size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

uint32_t		right_rot(uint32_t value, unsigned int count)
{
	return (value >> count | value << (32 - count));
}
