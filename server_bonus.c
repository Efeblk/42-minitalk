/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:12 by ibalik            #+#    #+#             */
/*   Updated: 2023/06/05 15:37:37 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	bit_handler(int sig)
{
	static int				bit_count = 0;
	static unsigned char	received_char = 0;

	received_char = (received_char >> 1) | ((sig == SIGUSR2) << 7);
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		write(1, &received_char, 1);
		received_char = 0;
	}
}

int	main(void)
{
	ft_printf("PID %d\n", getpid());
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	while (1)
		pause();
	return (0);
}
