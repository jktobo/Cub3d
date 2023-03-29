/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:08 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:56:11 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* find a char in the string if found return the index */

static int	find_index(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

/* search the second string from the first string if found
trim if there is space at the begining and end then return
the string*/

char	*ft_trim_line(char *long_str, char *search_let)
{
	char	*sub_line;
	char	*trim;
	int		index;
	char	*temp;

	sub_line = ft_strstr(long_str, search_let);
	if (sub_line)
	{
		sub_line += ft_strlen(search_let);
		while (*sub_line == ' ')
			sub_line++;
		index = find_index(sub_line, '\n');
		temp = sub_line + index;
		sub_line = ft_substr(sub_line, 0, index);
		trim = ft_strtrim(sub_line, " ");
		if (ft_strstr(temp, search_let))
		{
			printf("\nError!\nDuplicate key found\n");
			return (NULL);
		}
		free(sub_line);
		return (trim);
	}
	return (NULL);
}
