/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:43:19 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/27 23:44:00 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*swap_space_arg(char *command, char *what_change, char *to_swap)
{
	int	c;
	int	w;
	int	aux;

	c = 0;
	w = 0;
	aux = 0;
	while (command[c] != '\0')
	{
		while (command[c + w] == what_change[w])
		{
			command[c + w] = to_swap[aux];
			w++;
			aux++;
		}
		c++;
	}
	return (command);
}

char	**replace_in_matriz(char **matriz, char *what_change, char *to_swap)
{
	int	i;

	i = 1;
	while (matriz[i])
	{
		if (ft_strnstr(matriz[i], what_change))
		{
			free(matriz[i]);
			matriz[i] = ft_strdup(to_swap);
		}
		i++;
	}
	return (matriz);
}
