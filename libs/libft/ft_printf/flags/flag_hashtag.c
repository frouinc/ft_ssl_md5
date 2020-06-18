/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hashtag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:35 by cfrouin          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:55 by cfrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					flag_hashtag(t_printf_data **data)
{
	(*data)->hash = 1;
	(*data)->str = (*data)->str + 1;
	return (do_flags(data));
}
