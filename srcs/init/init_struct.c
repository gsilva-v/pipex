/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:50:35 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/23 09:52:36 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(char **argv, t_pipe *pipet, int argc)
{
	pipet->input = argv[argc - 4];
	pipet->firstcommand = argv[argc - 3];
	pipet->lastcommand = argv[argc - 2];
	pipet->output = argv[argc - 1];
}
