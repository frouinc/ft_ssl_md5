/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:46 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	if (s != NULL)
	{
		if ((str = malloc((len + 1) * sizeof(char))) == NULL)
			return (NULL);
		count = 0;
		while (count < len)
		{
			str[count] = s[count + start];
			++count;
		}
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
