/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:19 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					flag_x_next(t_printf_data **data, char *hexa
								, int size, unsigned long long x)
{
	int						len;

	len = 0;
	if ((*data)->zero[0] != 2)
		len = do_flag_zero(data, 0, size, 0);
	if ((*data)->hash == 1 && hexa[0] != '0' && (*data)->precision <= size)
		len += write(1, "0x", 2);
	if ((*data)->zero[0] == 2)
		len = do_flag_zero(data, 0, size, len);
	len += precision_char(data, hexa);
	if ((*data)->precision != -1 && x == 0)
	{
		free(hexa);
		return (len);
	}
	len += ft_putstr(hexa);
	len = do_flag_zero(data, 1, size, len);
	free(hexa);
	return (len);
}

int							flag_x(t_printf_data **data)
{
	unsigned long long		x;
	char					*hexa;
	int						size;

	x = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	if ((hexa = ft_longlong_to_hexa(x, "abcdef")) == NULL)
		return (-1);
	(*data)->plus = '\0';
	if ((int)ft_strlen(hexa) > (*data)->precision)
		size = (int)ft_strlen(hexa);
	else
		size = (*data)->precision;
	if ((*data)->hash == 1 && hexa[0] != '0' && (*data)->precision <= size)
		size += 2;
	if ((*data)->precision != -1 && x == 0)
		--size;
	return (flag_x_next(data, hexa, size, x));
}
