/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:45:53 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/18 22:23:04 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	arg_error(char *s1, char *s2)
{
	write(1, s1, ft_strlen(s1));
	write(1, s2, ft_strlen(s2));
	exit (INVALID_ARGS);
}

void	command_error(char *s)
{
	write (2, "bash: ", 6);
	write (2, s, ft_strlen(s));
	write (2, ": command not found\n", 20);
	exit(INVALID_COMAND);
}

char	*inv_fd(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit (INVALID_FD);
}

void	inv_arc(t_pipe *pipet)
{
	write(2, pipet->firstcommand, ft_strlen(pipet->firstcommand));
	write(2, ": ", 2);
	perror(pipet->input);
	exit(INVALID_ARC);
}
