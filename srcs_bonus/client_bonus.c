/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:45:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/17 11:46:50 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk_bonus.h"

void	send_msg(int server_pid, char *msg)
{
	unsigned char	character;
	int				bit;
	int				i;

	i = 0;
	while (msg[i] != '\0')
	{
		character = msg[i];
		bit = 7;
		while (bit >= 0)
		{
			if ((character >> bit & 1) == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(50);
			bit--;
		}
		i++;
	}
}

void	send_null(int server_pid)
{
	int		bit;
	char	null;

	bit = 7;
	null = '\0';
	while (bit >= 0)
	{
		if ((null >> bit & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(400);
		bit--;
	}
}

void	checkmessage(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signal == SIGUSR1)
	{
		ft_printf("%s\n", "Message received by and printed by the server!");
	}
	exit (1);
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
	struct sigaction	sa_newsignal;
	char				*msg;
	int					pid;

	if (check_input(argc, argv))
	{
		sa_newsignal.sa_sigaction = &checkmessage;
		sa_newsignal.sa_flags = SA_SIGINFO;
		pid = ft_atoi(argv[1]);
		msg = ft_strjoin(argv[2], "\n");
		if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1)
			ft_printf("%s\n", "Error! SIGUSR1 failed!");
		send_msg(pid, msg);
		free(msg);
		send_null(pid);
	}
	while (1)
		pause();
	return (0);
}
