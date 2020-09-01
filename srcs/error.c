/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:14:11 by cfrouin           #+#    #+#             */
/*   Updated: 2020/09/01 11:20:58 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			md5_error(char *message, int errno_display)
{
	if (errno_display)
		ft_printf("ft_ssl: md5: %s: %s\n", message, strerror(errno));
	else
		ft_printf("ft_ssl: md5: %s\n", message);
}
