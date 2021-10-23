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

void	init_struct(char **argv, t_pipe *pipet)
{
	pipet->input = argv[1];
	pipet->firstcommand = argv[2];
	pipet->lastcommand = argv[3];
	pipet->output = argv[4];
}
