/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:52:35 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/20 16:25:50 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(t_pipe *pipet, char **path_command)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (perror("wrong process"));
	pid = fork();
	if (pid == 0)
		first_command(pipet, fd, path_command);
	close (fd[1]);
	second_command(pipet, fd, path_command);
	close (fd[0]);
}

int	main(int argc, char **argv, char **path_command)
{
	t_pipe	pipet;

	init_struct(argv, &pipet);
	if (argc != 5)
		return (arg_error(INV_ARG, HOW_USE));
	pipex(&pipet, path_command);
	return (0);
}
