/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while(str[count])
		count++;
	return count;
}

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

int	ft_strncmp(char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	delete(t_piece *del)
{
	del->value = 0;
	del->index = 0;
	del->next = NULL;
	return 0;
}
