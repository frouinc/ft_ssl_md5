/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:44:13 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 12:39:25 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			call_operation_string(t_data *data, unsigned char *str)
{
	if (data->c_op != NULL)
	{
		if (data->quiet)
		{
			data->c_op->operation(str);
			ft_printf("\n");
		}
		else if (data->reverse)
		{
			data->c_op->operation(str);
			ft_printf(" \"%s\"\n", str);
		}
		else
		{
			ft_printf("%s (\"%s\") = ", ft_strtoupper(data->c_op->name), str);
			data->c_op->operation(str);
			ft_printf("\n");
		}
	}
}

void			call_operation_file(t_data *data, char *filename,
	unsigned char *str)
{
	if (data->c_op != NULL)
	{
		if (data->quiet)
		{
			data->c_op->operation(str);
			ft_printf("\n");
		}
		else if (data->reverse)
		{
			data->c_op->operation(str);
			ft_printf(" %s\n", filename);
		}
		else
		{
			ft_printf("%s (%s) = ", ft_strtoupper(data->c_op->name), filename);
			data->c_op->operation(str);
			ft_printf("\n");
		}
	}
}
