/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:52:35 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 18:08:37 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	check_comands(t_pipe *pipet)
{
	char *first;
	char *last;
	char **matriz;

	matriz = ft_split(pipet->firstcommand, ' ');
	pipet->exit_code = 0;
	first = check_access(matriz[0]);
	if (first == NULL)
		pipet->exit_code = 1;
	free_argv(matriz);
	matriz = ft_split(pipet->lastcommand, ' ');
	last = check_access(matriz[0]);
	if (last == NULL)
		pipet->exit_code = 1;
	free_argv(matriz);
	if (pipet->exit_code == 1)
		pipet->exit_code = 127;
	else
		pipet->exit_code = 0;
	free(first);
	free(last);
	return(pipet->exit_code);
}



void	pipex(t_pipe *pipet, char **path_command)
{
	int	fd[2];
	int	pid;
	
	pipet->exit_code = check_comands(pipet);	

	if (pipe(fd) == -1)
		return (perror("wrong process"));
	// what_path_2(pipet->firstcommand);
	pid = fork();
	if (pid == 0)
		first_command(pipet, fd, path_command);
	close (fd[1]);
	// what_path_2(pipet->lastcommand);
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
	// close_pipe(&pipet);
	printf("exit: %d\n", pipet.exit_code);
	return (pipet.exit_code);
}
