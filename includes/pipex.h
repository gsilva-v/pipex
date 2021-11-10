/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:56:38 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/10 19:10:13 by gsilva-v         ###   ########.fr       */
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
# include <errno.h>

# define INVALID_FD 5
# define INVALID_COMAND 127
# define INVALID_ARGS 0
# define INVALID_ARC 1
# define INV_ARG "Invalid args!\n"
# define HOW_USE "Try: './pipex infile <\"cmd1\"> <\"cmd2\"> outfile\n"
# define INV_COM "Invalid command! Try another!"
# define SPACE "0x0"
# define PATH "/usr/local/sbin/::/usr/local/bin/:\
/usr/sbin/:/usr/bin/:/sbin:/bin/"

typedef struct s_pipe
{
	char	*input;
	char	*output;
	char	*firstcommand;
	char	*lastcommand;
	int		fd_input;
	int		fd_output;
	int		exit_code;
}	t_pipe;

/*Utils*/
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t nbytes, size_t sizemem);
char	*ft_strnstr(const char *str, char *tofind);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
void	free_argv(char **argv);

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
void	exec_command(char *what_comand, char **path_command);
char	**atribute_flags(char **flags, char **argv);
char	*swap_space_arg(char *command, char *what_change, char *to_swap);
char	**replace_in_matriz(char **matriz, char *what_chance, char *to_swap);
char	*what_path(char *what_comand);
int		check_comands(t_pipe *pipet);
char	*check_access(char *what_comand);

#endif