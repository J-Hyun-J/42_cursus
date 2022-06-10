<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:37:49 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:37:50 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
#include "../includes/minishell.h"

int	have_to_change(char *part)
{
	int	i;

	i = 0;
	while (part[i])
	{
		if (is_quote(part[i]) || part[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*make_new_word(char *part, t_info *info)
{
	int		end;
	char	*res;
	t_word	w_info;

	w_info.len = get_word_len(part, info, 0, &end);
	res = (char *)malloc(sizeof(char) * (w_info.len + 1));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		return (0);
	}
	res[w_info.len] = '\0';
	w_info.start = 0;
	get_interpret_word(part, res, info, w_info);
	free(part);
	return (res);
}

int	interpret_word(char **parts, t_info *info)
{
	int	i;
	
	i = 0;
	while (parts[i])
	{
		if (have_to_change(parts[i]))
		{
			parts[i] = make_new_word(parts[i], info);
			if (!parts[i])
<<<<<<< HEAD
				return (0);
=======
			{
				free_str(parts);
				free_exit(info);
			}
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
		}
		i++;
	}
	return (1);
}