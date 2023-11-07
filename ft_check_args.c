/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= sign;
	return (nb);
}

void	ft_check_input(int argc, char **argv)
{
		int i;
		int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
			j++;
		else if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
		{
			write (2, "Error! Invalid input!", 21);
			return ;
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write (2, "Error! Only numbers, please!", 28);
				return ;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i >= 1 && argv[i + 1])
	{
		if (*argv[i] != *argv[i + 1] )
				i++;
		else if (*argv[i] == *argv[i + 1])
		{
			write (2, "Error! Numbers must be different!", 34);
			return ;
		}
		else if (ft_atoi(argv[i]) > INT_MAX)
		{
			write (2, "Error! Number bigger than upper limit!", 34);
			return ;
		}
		else if (ft_atoi(argv[i]) < INT_MIN)
		{
			write (2, "Error! Number smaller than lower limit!", 34);
			return ;
		}
	}
}

//check for 00 case