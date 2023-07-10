/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:51:21 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/10 00:51:53 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(int c)
{
	return (c >= '1' && c <= '9');
}

static int	ft_iswspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_isorange(unsigned long long result, int sign)
{
	if (result > LLONG_MAX && sign == -1)
		return (0);
	if (result > LLONG_MAX && sign == 1)
		return (-1);
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_iswspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	return (ft_isorange(result, sign));
}
