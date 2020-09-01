/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:55:54 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							flag_b(t_printf_data **data)
{
	unsigned long long		b;
	int						len;
	char					*binaire;

	b = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	if ((binaire = ft_longlong_to_binaire(b)) == NULL)
		return (-1);
	len = 0;
	len += ft_putstr(binaire);
	free(binaire);
	return (len);
}
