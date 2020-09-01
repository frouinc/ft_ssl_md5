/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hashtag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:55:56 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:56:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					flag_hashtag(t_printf_data **data)
{
	(*data)->hash = 1;
	(*data)->str = (*data)->str + 1;
	return (do_flags(data));
}
