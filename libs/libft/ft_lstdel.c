/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:34 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:31 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*tmp2;

	if (alst != NULL && (*del) != NULL)
	{
		tmp = *alst;
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp2;
		}
		*alst = NULL;
	}
}
