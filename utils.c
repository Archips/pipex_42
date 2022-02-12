/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:54:44 by athirion          #+#    #+#             */
/*   Updated: 2022/02/12 18:07:54 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open(char **argv, t_data *data)
{
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
}

int	ft_error(int error)
{
	ft_putstr_fd("./pipex: ", 2);
	if (error == 1)
		ft_putendl_fd(ERR_1, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_tab(char **tab)
{
	char	**temp;

	temp = tab;

	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab ++;
	}
	free(temp); 
	temp = NULL;
}

void	ft_free(t_data *data)
{
	if (data->env_path)
		ft_free_tab(data->env_path);
	if (data->arg_cmd1)
		ft_free_tab(data->arg_cmd1);
	if (data->arg_cmd2)
		ft_free_tab(data->arg_cmd2);
	if (cmd1)
	{
		free(cmd1);
		cmd1 = NULL;
	}


	ft_free_tab(
