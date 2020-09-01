/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:11 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int		size_dest;
	int		count;

	count = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (dest[count] != '\0')
		++count;
	size_dest = count;
	count = -1;
	while (src[++count] != '\0')
		dest[size_dest + count] = src[count];
	dest[size_dest + count] = '\0';
	return (dest);
}
