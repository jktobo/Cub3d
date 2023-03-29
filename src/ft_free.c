/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:17:27 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 02:29:55 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* free doule array*/

void	ft_freedouble(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	free(str);
	str = NULL;
}

/* free all the dynamically allocated memories*/

int	ft_free_all(t_map *map, int flag)
{
	free(map->long_str);
	free(map->ea);
	free(map->so);
	free(map->no);
	free(map->we);
	if (flag)
		ft_freedouble(map->map);
	return (1);
}
