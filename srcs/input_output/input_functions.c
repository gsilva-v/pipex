/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:50:12 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/23 09:51:06 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipe *pipet, int fd[], char **path_command)
{
	int	input_file;

	input_file = open(pipet->input, O_RDONLY);
	if (input_file == -1)
		return (inv_arc(pipet));
	if (dup2(input_file, STDIN_FILENO) < 0)
		return (perror("Invalid dup!"));
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (perror("Invalid dup!"));
	close(fd[1]);
	exec_command(pipet->firstcommand, path_command, pipet->input);
}

void	second_command(t_pipe *pipet, int fd[], char **path_command)
{
	int		output_file;

	unlink("outfile");
	output_file = open(pipet->output, O_WRONLY | O_CREAT, 0777);
	if (output_file == -1)
		return (perror("Fail to create outfile"));
	if (dup2(output_file, STDOUT_FILENO) < 0)
		return (perror("wrong dup"));
	if (dup2(fd[0], STDIN_FILENO) < 0)
		return (perror("wrong dup"));
	close (fd[0]);
	exec_command_another(pipet->lastcommand, path_command);
}
