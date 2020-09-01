/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:02 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							flag_u(t_printf_data **data)
{
	unsigned long long		u;
	int						len;
	int						size;

	u = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	(*data)->plus = '\0';
	if (ft_longlonglen_unsigned(u) > (*data)->precision)
		size = ft_longlonglen_unsigned(u);
	else
		size = (*data)->precision;
	if ((*data)->precision != -1 && u == 0)
		--size;
	len = do_flag_zero(data, 0, size, 0);
	len += precision_unsigned_long(data, u);
	if ((*data)->precision != -1 && u == 0)
		return (len);
	ft_putnbr_longlong_unsigned(u);
	len = do_flag_zero(data, 1, ft_longlonglen_unsigned(u), len);
	return (ft_longlonglen_unsigned(u) + len);
}
