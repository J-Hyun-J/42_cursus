/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:44:58 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/24 20:31:12 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	(void) num;
	g_sig.bit >>= 1;
}

struct sigaction	init(unsigned long int *len, char **argv)
{
	struct sigaction	act;

	*len = (ft_strlen(argv[2]) + 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = &handler;
	g_sig.pid = ft_atoi(argv[1]);
	return (act);
}

void	error_check(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client <server pid> \"<message>\"\n", 1);
		exit (0);
	}
	if (99 > ft_atoi(argv[1]) && ft_atoi(argv[1]) > 99998)
	{
		ft_putstr_fd("Wrong pid range!", 1);
		exit (0);
	}
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	unsigned long int	len;

	error_check(argc, (void *)&argv);
	act = init(&len, argv);
	sigaction(SIGUSR1, &act, 0);
	while (len--)
	{
		g_sig.bit = 0b10000000;
		while (g_sig.bit)
		{
			if (*argv[2] & g_sig.bit)
				kill(g_sig.pid, SIGUSR1);
			else
				kill(g_sig.pid, SIGUSR2);
			pause();
			usleep(50);
		}
		argv[2]++;
		if (len == 0)
			ft_putstr_fd("Message arrived successfully!\n", 1);
	}
	return (0);
}
