/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atribute_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:15:10 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/05 14:41:07 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**atribute_flags(char **flags, char **argv)
{
	int	i;

	i = -1;
	while (flags[++i])
		argv[i] = flags[i];
	argv[i] = NULL;
	return (argv);
}
