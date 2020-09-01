/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:55:58 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					flag_long(t_printf_data **data)
{
	long long		l;
	int				len;

	l = (long long)va_arg((*data)->ap, long);
	(*data)->str = (*data)->str + 1;
	len = precision_long(data, l);
	ft_putnbr((int)l);
	return (ft_longlonglen(l) + len);
}
