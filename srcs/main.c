/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:14:02 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/20 12:23:14 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				add_operation(t_data *data, char name[],
	void (*op_func)(unsigned char *))
{
	t_operation	*op;
	t_operation *last;

	if ((op = malloc(sizeof(t_operation))) == NULL)
		return (-1);
	op->name = ft_strdup(name);
	op->operation = op_func;
	op->next = NULL;
	if (data->op_list == NULL)
		data->op_list = op;
	else
	{
		last = data->op_list;
		while (last->next)
			last = last->next;
		last->next = op;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (-1);
	}
	data.c_op = 0;
	data.quiet = 0;
	data.print = 0;
	data.reverse = 0;
	data.had_file = 0;
	data.displayed = 0;
	data.op_list = NULL;
	add_operation(&data, "md5", md5);
	add_operation(&data, "sha256", sha256);
	add_operation(&data, "sha224", sha224);
	if (params(ac, av, &data) == -1)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", av[1]);
		return (-1);
	}
	return (1);
}
