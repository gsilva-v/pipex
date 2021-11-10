/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:52:35 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 19:09:11 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipe *pipet, char **path_command)
{
	int	fd[2];
	int	pid;

	pipet->exit_code = check_comands(pipet);
	if (pipe(fd) == -1)
		return (perror("wrong process"));
	pid = fork();
	if (pid == 0)
		first_command(pipet, fd, path_command);
	close (fd[1]);
	pid = fork();
	if (pid == 0)
		second_command(pipet, fd, path_command);
	waitpid(pid, NULL, 0);
	close (fd[0]);
}

int	main(int argc, char **argv, char **path_command)
{
	t_pipe	pipet;
	int		outfile;

	outfile = 0;
	init_struct(argv, &pipet, argc);
	if (argc != 5)
	{
		outfile = open(argv[argc - 1], O_CREAT | O_TRUNC, 0666);
		return (arg_error(INV_ARG, HOW_USE));
	}
	pipex(&pipet, path_command);
	return (pipet.exit_code);
}
