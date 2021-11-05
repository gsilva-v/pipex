/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:54 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/05 17:25:19 by gsilva-v         ###   ########.fr       */
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

void	exec_command(char *what_comand, char **path_command, char *my_param)
{
	char	**flags;
	char	**argv;
	int		how_many;
	char	*command;

	if (ft_strnstr(what_comand, " ' '"))
		what_comand = swap_space_arg(what_comand, " ' '", " 0x0");
	flags = ft_split(what_comand, ' ');
	flags = replace_in_matriz(flags, "0x0", "  ");
	how_many = how_many_flags(flags);
	argv = (char **)malloc(sizeof(char *) * (how_many + 1));
	what_comand = flags[0];
	what_path(what_comand, path_command);
	command = set_path();
	argv[0] = what_comand;
	argv[1] = my_param;
	argv = atribute_flags(flags, argv);
	if (access(command, F_OK) == 0)
		execve(command, argv, path_command);
	else
		command_error(what_comand);
	free_argv(argv);
	waitpid(command[0], NULL, 0);
}

void	exec_command_another(char *what_comand, char **path_command)
{
	char	**flags;
	char	**argv;
	int		how_many;
	char	*command;

	if (ft_strnstr(what_comand, " ' '"))
		what_comand = swap_space_arg(what_comand, " ' '", " 0x0");
	flags = ft_split(what_comand, ' ');
	flags = replace_in_matriz(flags, "0x0", "  ");
	how_many = how_many_flags(flags);
	argv = (char **)malloc(sizeof(char *) * (how_many + 1));
	what_comand = flags[0];
	what_another_path(what_comand, path_command);
	command = set_another_path();
	argv[0] = what_comand;
	argv = atribute_flags(flags, argv);
	if (access(command, F_OK) == 0)
		execve(command, argv, path_command);
	else
		command_error(what_comand);
	free_argv(argv);
	waitpid(command[0], NULL, 0);
}
