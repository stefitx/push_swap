/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	fill_index(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		j;
	int		index;
	t_piece	*ptr;

	i = 1;
	ptr = stack->first;
	while (ptr != NULL)
	{
		j = 1;
		index = 0;
		while (i < argc && j < argc)
		{
			if (ft_atoi(argv[j]) < ft_atoi(argv[i]))
				index++;
			j++;
		}
		ptr->index = index;
		i++;
		ptr = ptr->next;
	}
	return (0);
}

int	add_piece_to_stack(t_stack *stack, t_piece *new_piece)
{
	if (stack->len == 0 && stack->first == NULL)
	{
		stack->first = new_piece;
		stack->last = new_piece;
	}
	else
	{
		stack->last->next = new_piece;
		stack->last = new_piece;
		new_piece->next = NULL;
	}
	stack->len += 1;
	return (0);
}

void	free_stack_a_in_case_of_error(t_stack *stack_a, int num)
{
	int		i;
	t_piece	*tmp;
	t_piece	*tmp2;

	i = 0;
	tmp = stack_a->first;
	if (tmp != NULL)
	{
		while (i <= num)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
			i++;
		}
	}
}

int	fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	t_piece	*new_piece;
	int		i;

	i = 1;
	while (i < argc)
	{
		new_piece = malloc(sizeof(t_piece));
		if (!new_piece)
		{
			free_stack_a_in_case_of_error(stack_a, i - 1);
			return (0);
		}
		new_piece->value = (ft_atoi(argv[i++]));
		add_piece_to_stack(stack_a, new_piece);
	}
	return (1);
}

void	initialize_stack(t_stack *stack)
{
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}
