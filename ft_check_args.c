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


int	ft_check_string(char *str)
{
	int i;
	int error;

	error = 0;
	i = 0;
	if(str[0] == '\0')
		error = 1;
	else if (str[0] == '-')
	{
		i++;
		if(str[1] == '0')
			error = 1;
	}
	if (!error){
		while (str[i])
		{
			if (!ft_isdigit(str[i++]))
			{
				error = 1;
				break ;
			}
		}
	}
	if (!error)
		return(1);
	write (2, "Error! Invalid input!", 21);
	return (0);
}

int str_num_is_out_of_range(char *str_num)
{
	if (str_num[0] == '-')
	{
		//case is negative number
		if (ft_strlen(str_num) > 11)
			return(1);
		if (ft_strlen(str_num) < 11)
			return(0);
		if (ft_strncmp(str_num, "-2147483648", 11) > 0)
			return (1);
	}
	else
	{
		//case is positive number
		if (ft_strlen(str_num) > 10)
			return(1);
		if (ft_strlen(str_num) < 10)
			return(0);
		if (ft_strncmp(str_num, "2147483647", 10) > 0)
			return (1);
	}
	return(0);
}

int check_invalid_character_and_zeros(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_string(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int check_not_dups(int argc, char **argv)
{
	int i;
	int j;
	int num1;
	int num2;

	i = 1;
	while(i < argc)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while(j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if(num1 == num2)
			{
				write (2, "Error! duplicated num input!", 21);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//check for empty string param ./push_swap 1 2 "" 3
int	ft_check_input(int argc, char **argv)
{
	int i;

	i = 1;
	if (check_invalid_character_and_zeros(argc, argv) == 0)
		return (0);
	if (check_not_dups(argc, argv) == 0)
		return (0);
	while (i  < argc)
	{
		if (str_num_is_out_of_range(argv[i]))
		{
			write (2, "Error! Numbers is out of range!", 34);
			return (0);
		}
		i++;
	}
	return 1;
}
