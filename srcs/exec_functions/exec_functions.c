/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:54 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 16:50:45 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	how_many_flags(char **flags)
{
	int	i;

	i = 0;
	while (flags[i])
		i++;
	return (i + 1);
}

void	exec_command(char *what_comand, char **path_command)
{
	char	**flags;
	char	**argv;
	int		how_many;

	if (ft_strnstr(what_comand, " ' '"))
		what_comand = swap_space_arg(what_comand, " ' '", " 0x0");
	flags = ft_split(what_comand, ' ');
	flags = replace_in_matriz(flags, "0x0", "  ");
	how_many = how_many_flags(flags);
	argv = (char **)malloc(sizeof(char *) * (how_many + 1));
	argv = atribute_flags(flags, argv);
	what_comand = what_path(flags[0]);
	if (what_comand == NULL)
	{
		free_argv(argv);
		command_error(what_comand);
		return ;
	}
	else
		execve(what_comand, argv, path_command);
}
