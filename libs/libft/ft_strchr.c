/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:13 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char				*ft_strchr(const char *s, int c)
{
	size_t			len;
	unsigned char	tmp;

	if (s == NULL)
		return (NULL);
	tmp = (unsigned char)c;
	len = ft_strlen((char *)(uintptr_t)s);
	if (tmp == '\0')
		return ((char *)(uintptr_t)s + len);
	while (*s != '\0')
	{
		if (*s == tmp)
			return ((char *)(uintptr_t)s);
		s++;
	}
	return (NULL);
}
