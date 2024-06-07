/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:20:25 by malena-b          #+#    #+#             */
/*   Updated: 2024/06/07 13:52:52 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mshell_exec.h"

void	ft_env(t_cmds *cmd)
{
	(void)cmd;
}

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		perror("error at getcwd()");
	ft_printf("%s\n", cwd);
	free (cwd);
}

void	ft_echo(t_cmds *cmd)
{
	int	nnl_flag;
	int	i;

	nnl_flag = 0;
	i = 1;
	if (!ft_strncmp(cmd->cmds_flags[1], "-n", 3))
	{
		nnl_flag = 1;
		i = 2;
	}
	while (cmd->cmds_flags[i])
	{
		ft_putstr_fd(cmd->cmds_flags[i], 1);
		if (cmd->cmds_flags[i + 1])
			write (1, " ", 1);
	}
	if (!nnl_flag)
		write(1, "\n", 1);
}
