/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:18:18 by lumedeir          #+#    #+#             */
/*   Updated: 2023/09/08 15:34:25 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	free_split(char **str)
{
	int	index;

	index = -1;
	while (str[++index] != NULL)
	{
		free(str[index]);
		str[index] = NULL;
	}
	free(str);
}

void	error_finish(t_data *pipex, char *msg)
{
	if (pipex->paths != NULL)
		free_split(pipex->paths);
	if (pipex->cmd != NULL)
		free_split(pipex->cmd);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
