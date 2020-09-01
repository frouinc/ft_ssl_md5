/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:53 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:27 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	if (b == NULL)
		return (NULL);
	tmp = b;
	if (len == 0)
		return (b);
	while (--len >= 1)
		tmp[len] = (unsigned char)c;
	tmp[0] = (unsigned char)c;
	return (tmp);
}
