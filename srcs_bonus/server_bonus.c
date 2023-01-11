/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:45:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/11 10:53:03 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk_bonus.h"

void	print_char(int signal, siginfo_t *info, void *ucontent)
{
	static int	bit;
	static int	character;

	(void)ucontent;
	if (signal == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction	sa_newsignal;

	(void)argv;
	sa_newsignal.sa_sigaction = &print_char;
	sa_newsignal.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("%s\n", "Verify the input! Execute ./server");
		return(0);
	}
	ft_printf("%s", "Server PID: ");
	ft_printf("%d\n", pid);
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1)
		ft_printf("%s\n", "Error! SIGUSR1 failed to send!");
	if (sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
		ft_printf("%s\n", "Error! SIGUSR2 failed to send!");
	while (1)
			pause();
	return (0);
}
