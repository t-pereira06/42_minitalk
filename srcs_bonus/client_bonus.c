/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:45:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/09 13:06:05 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk.h"

void	send_msg(int server_pid, char msg)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (msg >> i & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	check_input(int argc, char **argv)
{
	int	input;

	input = 0;
	if (argc != 3)
		ft_printf("%s\n", "Verify the input! Execute ./client <PID> <message>");
	else if (ft_stronlydigits(argv[1]) == 0)
		ft_printf("%s", "Verify the PID. It can only contain numbers.");
	else if (ft_strlen(argv[2]) == 0)
		ft_printf("%s", "You can't send empty messages!");
	else
		input = 1;
	return (input);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	char	*msg;

	i = 0;
	if (check_input(argc, argv))
	{
		pid = ft_atoi(argv[1]);
		msg = ft_strdup(argv[2]);
		while (msg[i])
		{
			send_msg(pid, msg[i]);
			i++;
		}
		free(msg);
		send_msg(pid, '\n');
	}
	return (0);
}
