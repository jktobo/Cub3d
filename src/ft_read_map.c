/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:05:25 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 06:38:29 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* read the file and make it one line string*/

int	ft_read_map(char **line, int fd)
{
	int			size;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	size = 1;
	while (size > 0)
	{
		*line = ft_join(*line, buf);
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		buf[size] = '\0';
	}
	return (0);
}
