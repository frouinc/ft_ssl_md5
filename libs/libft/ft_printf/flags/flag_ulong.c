/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ulong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:03 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_ulong(t_printf_data **data)
{
	unsigned long long	ul;
	int					len;
	int					tmp;

	tmp = va_arg((*data)->ap, int);
	if (tmp < 0)
		ul = (unsigned long long)(ULONG_MAX + (unsigned long)tmp + 1);
	else
		ul = (unsigned long long)tmp;
	(*data)->str = (*data)->str + 1;
	len = (int)precision_unsigned_long(data, ul);
	ft_putnbr_longlong_unsigned(ul);
	return (ft_longlonglen_unsigned(ul) + len);
}
