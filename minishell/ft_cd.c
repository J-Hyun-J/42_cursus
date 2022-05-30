/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:41:23 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/05/31 04:28:19 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*concat_path(char *curr_path, char *rel_path)
{
	char	*new_path;
	int		i;
	int		j;

	new_path = malloc(sizeof(char) * (ft_strlen(curr_path) + 1 + \
	ft_strlen(rel_path) + 1));
	if (new_path == 0)
	{
		ft_error(0);
		return (0);
	}
	i = -1;
	while (curr_path[++i] != '\0')
		new_path[i] = curr_path[i];
	new_path[i] = '/';
	j = -1;
	while (rel_path[++j] != '\0')
		new_path[++i] = rel_path[j];
	new_path[++i] = '\0';
	return (new_path);
}

static int	handle_absolute(char *command, char *path)
{
	if (chdir(path) == -1)
	{
		ft_print_error(2, "cd", command, \
	strerror(errno));
		return (1);
	}
	//ft_pwd(PWD);pwd로 위치 불러오기
	return (0);
}

static int	handle_relative(char *command)
{
	char	*curr_path;
	char	*new_path;
	int		ret;

	curr_path = getcwd(NULL, 0);
	if (!curr_path)
	{
		ft_print_error(2, "cd", 0, strerror(errno));
		return (1);
	}
	new_path = concat_path(curr_path, command);
	if (!new_path)
	{
		free(curr_path);
		return (1);
	}
	ret = handle_absolute(command, new_path);
	free(curr_path);
	free(new_path);
	return (ret);
}

static int	handle_home(char **command, t_lexer *curr_lexer)
{
	char	*home_path;
	int		ret;

	if (get_env("HOME") == 0) //HOME이라는 이름의 환경 변수가 없을 때
		return (0);
	if (command[1][0] == 0)//cmd 뒤에 들어온 것이 없음
		home_path = concat_path(get_env("HOME")->val, "");
	else
		home_path = concat_path(get_env("HOME")->val, \
		&command[1][1]);
	ret = handle_absolute(command[1], home_path);
	free(home_path);
	return (ret);
}

int	ft_cd(char **command, t_info *info)
{
	t_list	*tmp;
	//int i; 필요한가에 대한 고민

	tmp = info->list;
	//OLDPWD 세팅
	if (command[1] == 0 || command[1][0] == '~' && \
	((command[1][1] == '\0') || (command[1][1] == '/'))) //cd, cd ~, cd ~/
		return (handle_home(command, tmp->next));
	if(command[1][0] == '/')
		return (handle_absolute(command[1], command[1]));
	else
		return (handle_relative(command[1]));
}