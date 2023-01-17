/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:13 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/17 11:41:43 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk.h"

void	print_char(int signal)
{
	static int	bit;
	static int	character;

	if (signal == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s\n", "Verify the input! Execute ./server");
	}
	else
	{
		ft_printf("%s", "Server PID: ");
		ft_printf("%d\n", pid);
		signal(SIGUSR1, print_char);
		signal(SIGUSR2, print_char);
		while (1)
			pause();
	}
	return (0);
}
