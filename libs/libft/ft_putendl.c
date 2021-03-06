/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:43:04 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:25 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char const *s)
{
	if (s != NULL)
	{
		if (ft_putstr(s) == -1)
			return (-1);
		return ((int)write(1, "\n", 1));
	}
	return (0);
}
