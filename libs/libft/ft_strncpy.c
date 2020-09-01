/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:39 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		count;

	count = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		++count;
	}
	while (count < n)
	{
		dest[count] = '\0';
		++count;
	}
	return (dest);
}
