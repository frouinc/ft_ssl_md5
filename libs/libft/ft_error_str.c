/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:09 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:40 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_error_str_void(char const *str)
{
	ft_putendl(str);
	return (NULL);
}

int			ft_error_str_int(char const *str)
{
	ft_putendl(str);
	return (-1);
}
