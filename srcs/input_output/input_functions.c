/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:50:12 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 19:03:20 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipe *pipet, int fd[], char **path_command)
{
	pipet->fd_input = open(pipet->input, O_RDONLY);
	if (pipet->fd_input == -1)
		return (inv_arc(pipet));
	if (dup2(pipet->fd_input, STDIN_FILENO) < 0)
		return (perror("Invalid dup!"));
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (perror("Invalid dup!"));
	close(fd[1]);
	exec_command(pipet->firstcommand, path_command);
}

void	second_command(t_pipe *pipet, int fd[], char **path_command)
{
	pipet->fd_output = open(pipet->output, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipet->fd_output == -1)
		return (perror("Fail to create outfile"));
	if (dup2(pipet->fd_output, STDOUT_FILENO) < 0)
		return (perror("wrong dup"));
	if (dup2(fd[0], STDIN_FILENO) < 0)
		return (perror("wrong dup"));
	close (fd[0]);
	exec_command(pipet->lastcommand, path_command);
}
