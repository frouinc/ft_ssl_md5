/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_upc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:04 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_upc(t_printf_data **data)
{
	wchar_t				c;
	int					len;

	c = (wchar_t)va_arg((*data)->ap, wchar_t);
	(*data)->str = (*data)->str + 1;
	(*data)->plus = '\0';
	len = do_flag_zero(data, 0, 1, 0);
	len += ft_wputchar(c);
	len = do_flag_zero(data, 1, 1, len);
	return (len);
}
