/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:31 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		if ((str = malloc(((ft_strlen((char *)(uintptr_t)s1)
			+ ft_strlen((char *)(uintptr_t)s2)) + 1) * sizeof(char))) == NULL)
			return (NULL);
		ft_bzero(str, ((ft_strlen((char *)(uintptr_t)s1)
			+ ft_strlen((char *)(uintptr_t)s2)) + 1));
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
