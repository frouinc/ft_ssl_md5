/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:07 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:41 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_error_close_void(int fd)
{
	close(fd);
	return (NULL);
}

int			ft_error_close_int(int fd)
{
	close(fd);
	return (0);
}

void		*ft_error_close_str_void(char const *str, int fd)
{
	close(fd);
	ft_putendl(str);
	return (NULL);
}

int			ft_error_close_str_int(char const *str, int fd)
{
	close(fd);
	ft_putendl(str);
	return (0);
}
