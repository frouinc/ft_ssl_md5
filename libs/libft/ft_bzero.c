/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:46:23 by cfrouin          #+#    #+#             */
/*   Updated: 2016/12/12 17:01:56 by cfrouin         ###   ########.fr       */
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
