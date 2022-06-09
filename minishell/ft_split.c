/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:38:39 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:38:40 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (!flag && s[i] != c)
		{
			flag = 1;
			count++;
		}
		else if (flag && s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

void	ft_findword(char const *s, char c, int *start, int *end)
{
	int	i;

	while (s[*start] == c)
		(*start)++;
	i = *start;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	*end = i;
}

void	ft_cpy(char *str, char const *s, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		start;
	int		end;

	str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	start = 0;
	end = 0;
	while (i < ft_wordcount(s, c))
	{
		ft_findword(s, c, &start, &end);
		str[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!str[i])
		{
			free_str(str);
			return (0);
		}
		ft_cpy(str[i++], s, start, end);
		start = end;
	}
	str[i] = 0;
	return (str);
}
