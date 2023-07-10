/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 04:28:43 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/10 01:39:18 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "minitalk.h"

void	handle_signal(int sig)
{
	static unsigned char	c;
	static int				bites_count;

	c = ((sig == SIGUSR2) << bites_count) | c;
	bites_count++;
	if (bites_count == 8)
	{	
		write(1, &c, 1);
		c = 0;
		bites_count = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
