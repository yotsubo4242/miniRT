/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:28 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/27 16:09:04 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_initgnl(t_gnl *gnl)
{
	gnl->str = NULL;
	gnl->len = 0;
	gnl->capa = 0;
}

unsigned char	ft_getc(int fd)
{
	static unsigned char	buf[BUFFER_SIZE];
	static unsigned char	*bufp = buf;
	static int				read_byte = 0;

	if (read_byte == 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
		{
			read_byte = 0;
			return (READ_ERROR);
		}
		if (read_byte == 0)
			return (EOF);
		bufp = buf;
	}
	if (--read_byte >= 0)
		return (*bufp++);
	else
		return (EOF);
}

int	ft_putc(t_gnl *gnl, char c)
{
	char	*nstr;

	if (gnl->len + 1 > gnl->capa)
	{
		nstr = (char *)malloc(sizeof(char) * (gnl->len + 1) * 2);
		if (!nstr)
			return (0);
		gnl->capa = (gnl->len + 1) * 2;
		ft_memcpy(nstr, gnl->str, gnl->len);
		free(gnl->str);
		gnl->str = nstr;
	}
	gnl->str[gnl->len++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	char	c;
	t_gnl	gnl;

	if (fd < 0)
		return (NULL);
	ft_initgnl(&gnl);
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
			return (free(gnl.str), NULL);
		if (c == EOF)
			break ;
		if (ft_putc(&gnl, c) == 0)
			return (free(gnl.str), NULL);
		if (c == '\n')
			break ;
	}
	if (gnl.len > 0 && ft_putc(&gnl, 0) == 0)
		return (free(gnl.str), NULL);
	return (gnl.str);
}
