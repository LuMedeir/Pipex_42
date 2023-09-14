/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:58:17 by lumedeir          #+#    #+#             */
/*   Updated: 2023/09/12 11:33:11 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <sys/wait.h>

typedef struct pipex {
	char	**paths;
	char	**temp_paths;
	char	**cmd;
	int		infile;
	int		outfile;
}	t_data;

void	error_finish(t_data *pipex, char *msg);
void	free_split(char **split);
void	fork_init(t_data *pipex, char **argv, char **envp);
void	find_path(t_data *pipex, char **envp);

#endif