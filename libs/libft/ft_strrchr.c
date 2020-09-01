/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:44 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen((char *)(uintptr_t)s);
	if ((unsigned char)c == '\0')
		return ((char *)(uintptr_t)s + len);
	s = s + len;
	while (len >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)(uintptr_t)s);
		s--;
		--len;
	}
	return (NULL);
}
