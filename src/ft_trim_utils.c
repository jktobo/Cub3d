/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:55:17 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:55:18 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub.h"

/* return the length of an array*/

int	ft_array_length(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* check if the string is digit*/

int	is_digit(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}	
	return (1);
}
