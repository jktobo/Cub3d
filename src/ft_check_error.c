/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:57:36 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:57:38 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*check if the argument is valid*/

int	ft_check_error(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg("Invalid number of argument.\n"));
	if ((ft_strlen(argv[1]) < 4) || (!ft_strchr(argv[1], '.')))
		return (error_msg("Invalid argument.\n"));
	if (ft_strcmp(ft_strchr(argv[1], '.'), ".cub") != 0)
		return (error_msg("Invalid map type.\n"));
	return (0);
}

/* display error message*/

int	error_msg(char *msg)
{
	printf("\nError!\n");
	printf("%s\n", msg);
	exit(1);
}
