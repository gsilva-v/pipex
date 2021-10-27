/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:56:38 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/20 17:01:37 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>//open
# include <sys/types.h>//wait
# include <sys/wait.h>//wait
# include <unistd.h>// execve e outros
# include <stdlib.h>//malloc
# include <stdio.h>//perror
# include <string.h>//strerror

# define INVALID_FD 5
# define INVALID_COMAND 127
# define INVALID_ARGS 0
# define INVALID_ARC 10
# define INV_ARG "Invalid args!\n"
# define HOW_USE "Try: './pipex infile <\"cmd1\"> <\"cmd2\"> outfile\n"
# define INV_COM "Invalid command! Try another!"
# define SPACE "0x0"

typedef struct s_pipe
{
	char	*input;
	char	*output;
	char	*firstcommand;
	char	*lastcommand;

}	t_pipe;

/*Utils*/
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t nbytes, size_t sizemem);
char	*ft_strnstr(const char *str, char *tofind);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);

/*funções de erro*/
int		arg_error(char *s1, char *s2);
void	command_error(char *s);
char	*inv_fd(char *s);
void	inv_arc(t_pipe *pipet);

/*inicialização*/
void	init_struct(char **argv, t_pipe *pipet, int argc);
void	pipex(t_pipe *pipet, char **path_command);
void	first_command(t_pipe *pipet, int fd[], char **path_command);
void	second_command(t_pipe *pipet, int fd[], char **path_command);
void	exec_command(char *what_comand, char **path_command, char *my_program);
void	exec_command_another(char *what_comand, char **path_command);
char	*swap_space_arg(char *command, char *what_change, char *to_swap);
char	**replace_in_matriz(char **matriz, char *what_chance, char *to_swap);
char	*what_path(char *what_comand, char **path_comand);
char	*what_another_path(char *what_comand, char **path_comand);
char	*set_path(void);
char	*set_another_path(void);
void	format_buffer(char *buffer);

#endif