/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:47:14 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 19:02:33 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*what_path(char *what_comand)
{
	int		pos;
	char	**path_comand;
	char	*command_which;

	path_comand = ft_split(PATH, ':');
	pos = 0;
	while (path_comand[pos] != NULL)
	{
		command_which = ft_strjoin(path_comand[pos], what_comand);
		if (access(command_which, F_OK) == 0)
		{
			free_argv(path_comand);
			return (command_which);
		}
		free(command_which);
		pos++;
	}
	free_argv(path_comand);
	command_error(what_comand);
	return (NULL);
}

char	*check_access(char *what_comand)
{
	int		pos;
	char	**path_comand;
	char	*command_which;

	path_comand = ft_split(PATH, ':');
	pos = 0;
	while (path_comand[pos] != NULL)
	{
		command_which = ft_strjoin(path_comand[pos], what_comand);
		if (access(command_which, F_OK) == 0)
		{
			free_argv(path_comand);
			return (command_which);
		}
		free(command_which);
		pos++;
	}
	free_argv(path_comand);
	return (NULL);
}
