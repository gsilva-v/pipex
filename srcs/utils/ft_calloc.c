/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:42:49 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/27 23:42:50 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *mem, int c, size_t len)
{
	while (len--)
	{
		*(unsigned char *)(mem + len) = (unsigned char)(c);
	}
	return (mem);
}	

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nbytes, size_t sizemem)
{
	void	*ptr;

	ptr = malloc(nbytes * sizemem);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (nbytes * sizemem));
	return (ptr);
}
