/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:45:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/06 12:03:49 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk_bonus.h"

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
	(void)argv;
	int	pid;

	pid = getpid();
	if (argc != 1)
	{
		ft_printf("%s\n", "Verify the input! Execute ./server");
	}
	ft_printf("%s", "Server PID: ");
	ft_printf("%d\n", pid);
	signal(SIGUSR1, print_char);
	signal(SIGUSR2, print_char);
	while (1)
		pause();
	return (0);
}
