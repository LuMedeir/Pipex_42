/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:58:14 by lumedeir          #+#    #+#             */
/*   Updated: 2023/09/12 14:24:36 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	open_file(t_data *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		ft_putstr_fd("Error to open infile\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex->outfile = open(argv[4],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		ft_putstr_fd("Error to open outfile\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	pipex;

	if (argc != 5)
	{
		if (argc > 5)
			ft_putstr_fd("Error: Too many arguments!\n", 2);
		if (argc < 5)
			ft_putstr_fd("Error: Too few arguments!\n", 2);
		exit(EXIT_FAILURE);
	}
	open_file(&pipex, argv);
	find_path(&pipex, envp);
	fork_init(&pipex, argv, envp);
	return (0);
}
