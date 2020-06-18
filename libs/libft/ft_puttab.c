/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:31:42 by cfrouin          #+#    #+#             */
/*   Updated: 2017/02/08 18:05:57 by cfrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_puttab(char **tab)
{
	int		count;

	count = -1;
	if (tab == NULL)
		return (0);
	while (tab[++count] != NULL)
		if (ft_putendl(tab[count]) == -1)
			return (-1);
	return (1);
}
