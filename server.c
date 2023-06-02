/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:12 by ibalik            #+#    #+#             */
/*   Updated: 2023/06/02 14:51:22 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdio.h>

void bit_handler(int sig)
{
    static int shift = 0;
    static char c;

    if (shift == 7)
    {
        shift = 0;
        c = 0;
    }

    c = c << shift | sig;
    shift++;
    usleep(300);
    
    printf("%d", c);
}


int main(void)
{
    printf("PID %d\n", getpid());
    signal(SIGUSR2, bit_handler);
    signal(SIGUSR1, bit_handler);
    while (1)
        pause();
    return (0);
}
