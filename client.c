/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 04:27:47 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/10 00:53:58 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		sig;

	if (ac == 3)
	{
		i = 0;
		while (av[2][i])
		{
			j = 0;
			while (j < 8)
			{
				sig = (av[2][i] >> j & 1);
				if (sig == 0)
					kill(ft_atoi(av[1]), SIGUSR1);
				else
					kill(ft_atoi(av[1]), SIGUSR2);
				usleep(80);
				j++;
			}
			i++;
		}
	}
	return (0);
}
