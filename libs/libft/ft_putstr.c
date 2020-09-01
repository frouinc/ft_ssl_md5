/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:43:17 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putstr(const char *s)
{
	if (s != NULL)
		return ((int)write(1, s, ft_strlen((char *)(uintptr_t)s)));
	return (-1);
}
