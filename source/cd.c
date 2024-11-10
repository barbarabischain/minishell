/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:21 by babischa          #+#    #+#             */
/*   Updated: 2024/11/06 19:32:13 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	matrix_size(char **matrix)
// {
// 	int	count;

// 	count = 0;
// 	while (matrix[count])
// 		count++;
// 	return (count);
// }

void	update_env(char	*old_pwd, char *pwd)
{
	unset_env(shell()->env_list, "OLDPWD");
	export_env(shell()->env_list, ft_strdup("OLDPWD"), ft_strdup(old_pwd));
	unset_env(shell()->env_list, "PWD");
	export_env(shell()->env_list, ft_strdup("PWD"), ft_strdup(pwd));
	free(old_pwd);
	free(pwd);
}

void	cd(char **cmd_matrix)
{
	char		*path;
	char		*old_pwd;
	t_env_list	*tmp_env;

	if (matrix_len(cmd_matrix) > 2)
	{
		printf("cd: too many arguments\n");
		free_matrix(cmd_matrix);
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (!cmd_matrix[1] || !ft_strcmp(cmd_matrix[1], "~"))
	{
		tmp_env = lst_find(shell()->env_list, "HOME");
		path = tmp_env->value;
	}
	else
		path = cmd_matrix[1];
	if(chdir(path) == -1)
		printf("cd: %s: No such file or directory\n", path);
	update_env(old_pwd, getcwd(NULL, 0));
	free_matrix(cmd_matrix);
}