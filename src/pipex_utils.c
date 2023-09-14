/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:16:29 by lumedeir          #+#    #+#             */
/*   Updated: 2023/09/12 15:13:41 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	get_path(t_data *pipex, char **envp)
{
	int		index;

	index = 0;
	while (envp[index] != NULL && ft_strncmp("PATH", envp[index], 4) != 0)
		index++;
	pipex->temp_paths = ft_split(&envp[index][5], ':');
}

void	find_path(t_data *pipex, char **envp)
{
	int		i;

	i = 0;
	get_path(pipex, envp);
	while (pipex->temp_paths[i] != NULL)
		i++;
	pipex->paths = malloc(sizeof(char *) * (i + 1));
	if (pipex->paths == NULL)
	{
		free_split(pipex->temp_paths);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (pipex->temp_paths[++i] != NULL)
		pipex->paths[i] = ft_strjoin(pipex->temp_paths[i], "/");
	pipex->paths[i] = NULL;
	free_split(pipex->temp_paths);
}

static void	exec_cmd(t_data *pipex, char *command, char **envp)
{
	int		index;
	char	*temp;

	pipex->cmd = ft_split(command, ' ');
	index = -1;
	while (pipex->cmd[++index] != NULL)
		pipex->cmd[index] = ft_strtrim(pipex->cmd[index], "'");
	index = -1;
	while (pipex->paths[++index])
	{
		temp = ft_strjoin(pipex->paths[index], pipex->cmd[0]);
		if (access(temp, F_OK) == 0 && execve(temp, pipex->cmd, envp) == -1)
		{
			free(temp);
			error_finish(pipex, "Error to execute the command\n");
		}
		free(temp);
	}
	error_finish(pipex, "Error to find path\n");
}

void	fork_init(t_data *pipex, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_finish(pipex, "Pipe could not be created\n");
	pid = fork();
	if (pid == -1)
		error_finish(pipex, "Error to init fork\n");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		exec_cmd(pipex, argv[2], envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		exec_cmd(pipex, argv[3], envp);
	}
}
