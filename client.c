/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:53:34 by ibalik            #+#    #+#             */
/*   Updated: 2023/06/02 14:53:35 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void send_bit(int pid, char *str, size_t len)
{
    int shift;
    size_t i;

    i = 0;
    while (i < len)
    {
        shift = 0;
        while (shift < 8)
        {
            if ((str[i] >> shift) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            shift++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    char *str;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        send_bit(pid, str, ft_strlen(str));
    }
    else
        ft_printf("\n error \n\n");

    return 0;
}
