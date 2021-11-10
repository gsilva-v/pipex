/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:06:30 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 19:06:30 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_comands(t_pipe *pipet)
{
	char	*first;
	char	*last;
	char	**matriz;

	matriz = ft_split(pipet->firstcommand, ' ');
	pipet->exit_code = 0;
	first = check_access(matriz[0]);
	free_argv(matriz);
	matriz = ft_split(pipet->lastcommand, ' ');
	last = check_access(matriz[0]);
	if (first == NULL || last == NULL)
		pipet->exit_code = 1;
	free_argv(matriz);
	if (pipet->exit_code == 1)
		pipet->exit_code = 127;
	else
		pipet->exit_code = 0;
	free(first);
	free(last);
	return (pipet->exit_code);
}
