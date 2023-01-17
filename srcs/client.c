/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/17 11:31:03 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minitalk.h"

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
	char	*msg;
	int		i;
	int		pid;

	i = 0;
	if (check_input(argc, argv))
	{
		pid = ft_atoi(argv[1]);
		msg = ft_strjoin(argv[2], "\n");
		send_msg(pid, msg);
		free(msg);
	}
	return (0);
}
