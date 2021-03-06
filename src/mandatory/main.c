/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:51:42 by athirion          #+#    #+#             */
/*   Updated: 2022/03/03 21:30:30 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(int argc, char **argv, char **envp, t_data *data)
{
	if (!envp)
		exit(EXIT_FAILURE);
	data->ac = argc;
	data->av = argv;
	data->env = envp;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->file_in = -1;
	data->file_out = -1;
	data->nb_cmd = data->ac - 3;
	ft_open(data);
	data->env_path = ft_get_path(data->env);
	data->index = 2;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		status;

	data.prog_name = ft_strrchr(argv[0], '/') + 1;
	status = 1;
	if (argc == 5)
	{
		status = 0;
		ft_init_data(argc, argv, envp, &data);
		if (data.file_in != -1)
			if (dup2(data.file_in, STDIN_FILENO) == -1)
				ft_exit(&data, ENOENT, data.av[1]);
		status = ft_pipex(&data, status);
		if (data.file_in != -1)
			ft_close(&data, &data.file_in);
		ft_close(&data, &data.file_out);
		ft_free_tab(data.env_path);
		ft_close_std();
		exit(status);
	}
	ft_putstr_fd(data.prog_name, 2);
	ft_putendl_fd(": Error: Wrong number of arguments", 2);
	ft_close_std();
	exit(status);
}
