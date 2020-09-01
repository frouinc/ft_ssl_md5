/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:33 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	size_dest;

	if (dest == NULL || src == NULL)
		return (0);
	count = 0;
	while (count < size && dest[count] != '\0')
		++count;
	size_dest = count;
	while (src[count - size_dest] != '\0' && count < (size - 1))
	{
		dest[count] = src[count - size_dest];
		++count;
	}
	if (size_dest < size)
		dest[count] = '\0';
	return (size_dest + ft_strlen((char *)(uintptr_t)src));
}
