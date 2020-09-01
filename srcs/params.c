/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:34:35 by cfrouin           #+#    #+#             */
/*   Updated: 2020/09/01 11:06:18 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			use_input(t_data *data)
{
	char		*str;
	char		*tmp;
	char		buff[50];
	int			ret;

	str = ft_strdup("");
	buff[49] = 0;
	ft_memset(buff, 0, 50);
	while ((ret = read(0, buff, 49)) > 0)
	{
		buff[49] = 0;
		if (data->print == 1)
			ft_printf("%s", buff);
		tmp = str;
		str = ft_strjoin(str, buff);
		ft_strclr(buff);
		free(tmp);
	}
	if (ret != -1)
	{
		data->c_op->operation((unsigned char *)str);
		ft_putchar('\n');
	}
	free(str);
	return ;
}

static int		check_option(int i, int ac, char **av, t_data *data)
{
	if (ft_strcmp(av[i], "-p") == 0)
	{
		data->print = 1;
		use_input(data);
		data->displayed = 1;
	}
	if (ft_strcmp(av[i], "-q") == 0)
		data->quiet = 1;
	if (ft_strcmp(av[i], "-r") == 0)
		data->reverse = 1;
	if (ft_strcmp(av[i], "-s") == 0)
	{
		if (i + 1 >= ac)
			return (-1);
		call_operation_string(data, (unsigned char *)av[i + 1]);
		return (2);
	}
	return (1);
}

static int		check_param(int i, int ac, char **av, t_data *data)
{
	char		*str;

	if (data->had_file == 0 && av[i][0] == '-')
		return (check_option(i, ac, av, data));
	data->had_file = 1;
	if ((str = ft_read_file(av[i])) == NULL)
		return (-2);
	call_operation_file(data, av[i], (unsigned char *)str);
	free(str);
	return (1);
}

static int		find_op(t_data *data, char *name)
{
	t_operation	*current;

	current = data->op_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			data->c_op = current;
			return (1);
		}
		current = current->next;
	}
	return (-1);
}

int				params(int ac, char **av, t_data *data)
{
	int			i;
	int			tmp;

	if (find_op(data, av[1]) == -1)
		return (-1);
	i = 2;
	while (i < ac)
	{
		if ((tmp = check_param(i, ac, av, data)) == -1)
			return (-1);
		i += (tmp == -2) ? 1 : tmp;
	}
	if (data->displayed == 0)
		use_input(data);
	return (1);
}
