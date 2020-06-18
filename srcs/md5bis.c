/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:27:29 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 12:39:20 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int					get_output_len(unsigned char *string)
{
	int len;
	int new_len;

	len = ft_strlen((char *)string);
	new_len = ((len + 8) / 64) * 64 + 64;
	return (new_len);
}

int					reverse_int(int num)
{
	int				new;

	new = 0;
	new += num << 24 & 0xff000000;
	new += num << 8 & 0xff0000;
	new += num >> 8 & 0xff00;
	new += num >> 24 & 0xff;
	return (new);
}
