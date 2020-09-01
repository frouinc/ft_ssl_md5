/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:00 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_percent(t_printf_data **data)
{
	int					len;

	(*data)->str = (*data)->str + 1;
	len = do_flag_zero(data, 0, 1, 0);
	len += (int)write(1, "%", 1);
	if ((*data)->zero[1] != 0)
		len = do_flag_zero(data, 1, 1, len);
	return (len);
}
