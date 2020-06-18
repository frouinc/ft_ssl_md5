/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:50:06 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 12:53:52 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_read_file_bis(char *str, long ret, int fd)
{
	close(fd);
	if (ret == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char			*ft_read_file(char *filename)
{
	char		*str;
	char		*tmp;
	char		buff[50];
	long		ret;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("%s\n", strerror(errno));
		return (NULL);
	}
	str = ft_strdup("");
	buff[49] = 0;
	ft_strclr(buff);
	while ((ret = read(fd, buff, 49)) > 0)
	{
		buff[49] = 0;
		tmp = str;
		str = ft_strjoin(str, buff);
		ft_strclr(buff);
		free(tmp);
	}
	return (ft_read_file_bis(str, ret, fd));
}
