/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:45:53 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/15 16:39:04 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	arg_error(char *s1, char *s2)
{
	
	write(1, s1, ft_strlen(s1));
	write(1, s2, ft_strlen(s2));
	return (-1);
}

void	command_error(char *s)
{
	char *error;
	
	error = malloc(sizeof(char *) * ft_strlen(s));
	error = ft_strdup(s);
	write (2, "bash: ", 6);
	write (2, error, ft_strlen(error));
	write (2, ": command not found\n", 20);
}