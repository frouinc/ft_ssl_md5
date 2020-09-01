/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:04 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:42 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		count;
	char		*tmp;

	if (s == NULL)
		return ;
	count = 0;
	tmp = s;
	while (count < n)
	{
		tmp[count] = 0;
		++count;
	}
}
