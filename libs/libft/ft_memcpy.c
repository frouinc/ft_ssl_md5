/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:49 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:28 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*tmp;
	const char	*tmp2;

	if (dest == NULL || src == NULL)
		return (NULL);
	tmp = dest;
	tmp2 = src;
	count = 0;
	while (count < n)
	{
		tmp[count] = tmp2[count];
		++count;
	}
	return (tmp);
}
