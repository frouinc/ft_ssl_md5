/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:21 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			precision_long(t_printf_data **data, long long nbr)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = ft_longlonglen(nbr);
		count = (*data)->precision - count;
		if (count > 0)
			len = count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}

int			precision_unsigned_long(t_printf_data **data
				, unsigned long long nbr)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = ft_longlonglen_unsigned(nbr);
		count = (*data)->precision - count;
		if (count > 0)
			len = count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}

int			precision_char(t_printf_data **data, char *str)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = (int)ft_strlen(str);
		count = (*data)->precision - count;
		if (count > 0)
			len = (int)count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}
