/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/get_next_line/get_next_line.h"

int	is_correct_movement(char *s)
{
	if (ft_strcmp(s, "sa\n") == 0 || ft_strcmp(s, "sb\n") == 0
		|| ft_strcmp(s, "ss\n") == 0 || ft_strcmp(s, "pa\n") == 0
		|| ft_strcmp(s, "pb\n") == 0 || ft_strcmp(s, "ra\n") == 0
		|| ft_strcmp(s, "rb\n") == 0 || ft_strcmp(s, "rra\n") == 0
		|| ft_strcmp(s, "rrb\n") == 0 || ft_strcmp(s, "rrr\n") == 0
		|| ft_strcmp(s, "rr\n") == 0)
		return (1);
	return (0);
}

void	check_sorted_stack(void)
{
	char	*line;

	line = get_next_line(0);
	if (line != NULL)
	{
		if (!is_correct_movement(line))
			write(2, "Error\n", 6);
		else
			write(1, "KO\n", 3);
		free(line);
	}
	else
		write(1, "OK\n", 3);
}

void	evaluate_final_result(t_stack	*stack_a, t_stack *stack_b)
{
	if (!sorted(stack_a) || stack_b->len != 0)
		write(1, "KO\n", 3);
	else if (sorted(stack_a) && stack_b->len == 0)
		write(1, "OK\n", 3);
}

void	check_non_sorted_stack(t_stack	*stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			evaluate_final_result(stack_a, stack_b);
			return ;
		}
		if (!is_correct_movement(line))
		{
			write(2, "Error\n", 7);
			return ;
		}
		if (line == NULL)
			break ;
		move(line, stack_a, stack_b);
		free(line);
	}
	evaluate_final_result(stack_a, stack_b);
}
