/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:43 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	count;
	size_t	count2;
	size_t	size_little;
	size_t	tmp;

	size_little = ft_strlen((char *)(uintptr_t)to_find);
	if (size_little == 0)
		return ((char *)(uintptr_t)str);
	count = 0;
	while (str[count] != '\0')
	{
		count2 = 0;
		tmp = count;
		while (str[count] == to_find[count2] && str[count] != '\0'
			&& count < len)
		{
			++count;
			++count2;
		}
		if (count2 == size_little)
			return ((char *)(uintptr_t)&str[count - size_little]);
		count = tmp;
		++count;
	}
	return (NULL);
}
