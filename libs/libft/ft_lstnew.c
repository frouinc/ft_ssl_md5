/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:42:42 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 13:43:30 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*ptr;

	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	if ((ptr = malloc(content_size)) == NULL)
		return (NULL);
	list->content = ft_memcpy(ptr, (void *)(uintptr_t)content, content_size);
	list->content_size = content_size;
	return (list);
}
