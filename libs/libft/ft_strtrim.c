/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:44:49 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:45:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		count;
	size_t	size;
	char	*str;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *)(uintptr_t)s);
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
		size--;
	count = -1;
	while (s[++count] == ' ' || s[count] == '\t' || s[count] == '\n')
		size--;
	if (size <= 0)
		size = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	s = s + count;
	count = -1;
	while (++count < (int)size)
		str[count] = *s++;
	str[count] = '\0';
	return (str);
}
