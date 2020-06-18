/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:43:17 by cfrouin          #+#    #+#             */
/*   Updated: 2017/10/04 17:38:06 by cfrouin         ###   ########.fr       */
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
