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

int out_of_range(char *str_num)
{
	int	error;

	error = 0;
	if (str_num[0] == '-')
	{
		if (ft_strlen(str_num) > 11)
			error = 1;
		if (ft_strlen(str_num) < 11)
			return (0);
		if (ft_strncmp(str_num, "-2147483648", 11) > 0)
			error = 1;
	}
	else
	{
		if (ft_strlen(str_num) > 10)
			error = 1;
		if (ft_strlen(str_num) < 10)
			return (0);
		if (ft_strncmp(str_num, "2147483647", 10) > 0)
			error = 1;
	}
	return (error);
}

int	check_character_mistakes(int argc, char **argv)
{
	int i;
	int	j;
	int	error;

	error = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if(argv[i][0] == '\0')
			error = 1;
		else if (argv[i][0] == '-')
		{
			j++;
			if(argv[i][1] == '0')
				error = 1;
		}
		if (!error)
		{
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j++]))
				{
					error = 1;
					break ;
				}
			}
		}
		i++;
	}
	return (error);
}

int check_dups(int argc, char **argv)
{
	int i;
	int j;
	int num1;
	int num2;
	int	error;

	error = 0;
	i = 1;
	while(i < argc)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while(j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if(num1 == num2)
				error = 1;
			j++;
		}
		i++;
	}
	return (error);
}

int	ft_check_input(int argc, char **argv)
{
	int i;
	int	error;

	error = 0;
	i = 1;
	if (argc < 2)
		error = 1;
	if (check_character_mistakes(argc, argv))
		error = 1;
//	printf("after char mistakes %d\n", error);
	if (check_dups(argc, argv))
		error = 1;
//	printf("after dups %d\n", error);
	while (i  < argc)
	{
		if (out_of_range(argv[i]))
			error = 1;
		i++;
	}
//	printf("after range %d\n", error);
	if (error == 1)
		printf("%s", "Error\n");
	return (error);
}
