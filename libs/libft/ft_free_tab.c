/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:12 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:39 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while ((*tab)[++i])
			free((*tab)[i]);
		free(*tab);
		*tab = NULL;
	}
}
