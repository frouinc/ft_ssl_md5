/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:43:05 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:25 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		if (write(fd, s, ft_strlen((char *)(uintptr_t)s)) == -1)
			return (-1);
		return ((int)write(fd, "\n", 1));
	}
	return (1);
}
