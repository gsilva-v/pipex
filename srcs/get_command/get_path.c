/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:47:14 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/20 16:55:43 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*what_path(char *what_comand, char **path_comand)
{
	int		pid;
	char	*argv[3];

	pid = fork();
	if (pid == 0)
	{
		argv[0] = "which";
		argv[1] = what_comand;
		argv[2] = NULL;
		close (STDOUT_FILENO);
		open ("comand_path", O_CREAT | O_WRONLY, 0666, "\0");
		execve("/usr/bin/which", argv, path_comand);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

char	*set_path(void)
{
	char	*buffer;
	int		fd;
	int		n_bytes;
	char	*to_return;

	fd = open("comand_path", O_RDONLY);
	buffer = ft_calloc(51, sizeof(char));
	n_bytes = read(fd, buffer, 50);
	format_buffer(buffer);
	to_return = malloc(sizeof(char) * n_bytes);
	to_return = ft_strdup(buffer);
	free(buffer);
	unlink("comand_path");
	return (to_return);
}

char	*what_another_path(char *what_comand, char **path_comand)
{
	int		pid;
	char	*argv[3];

	pid = fork();
	if (pid == 0)
	{
		argv[0] = "which";
		argv[1] = what_comand;
		argv[2] = NULL;
		close (STDOUT_FILENO);
		open ("comand_another_path", O_CREAT | O_WRONLY, 0666, "\0");
		if (execve("/usr/bin/which", argv, path_comand) == -1)
			command_error(what_comand);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

char	*set_another_path(void)
{
	char	*buffer;
	int		fd;
	int		n_bytes;
	char	*to_return;

	fd = open("comand_another_path", O_RDONLY);
	buffer = ft_calloc(51, sizeof(char));
	n_bytes = read(fd, buffer, 50);
	format_buffer(buffer);
	to_return = malloc(sizeof(char) * n_bytes);
	to_return = ft_strdup(buffer);
	free(buffer);
	unlink("comand_another_path");
	return (to_return);
}

void	format_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break ;
		}
		i++;
	}
}
