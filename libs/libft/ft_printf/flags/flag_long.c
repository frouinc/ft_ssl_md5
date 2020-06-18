/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:54 by cfrouin          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:40 by cfrouin         ###   ########.fr       */
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
