/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:02 by atudor            #+#    #+#             */
/*   Updated: 2023/11/21 12:40:51 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	smallest_index(t_stack *stack)
{
	t_piece *ptr;
	int	index;

	if (stack->len == 0)
		return (-1);
	index = stack->first->index;
	ptr = stack->first;
	while (ptr != NULL)
	{
		if (ptr->index < index)
			index = ptr->index;
		ptr = ptr->next;
	}
	return (index);
}

int	biggest_index(t_stack *stack)
{
	t_piece *ptr;
	int	index;

if (stack->len == 0)
	return -1;
	index = stack->first->index;
	ptr = stack->first;
	while (ptr != NULL)
	{
		if (ptr->index > index)
			index = ptr->index;
		ptr = ptr->next;
	}
	return (index);
}

int	sorted(t_stack *stack)
{
	t_piece	*iterator;

	iterator = stack->first;
	while (iterator->next != NULL)
	{
		if (iterator->index > iterator->next->index)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

int average(t_stack *stack)
{
	int		temp;
	int		average;
	int		count;
	t_piece	*ptr_piece;

	average = 0;
	count = 0;
	ptr_piece = stack->first;
	while (ptr_piece != NULL)
	{
		temp = ptr_piece->index;
		average += temp;
		ptr_piece = ptr_piece->next;
		count++;
	}
	average = average / count;
	//printf("AVERAGE INDEX IS %d\n", average);
	return (average);
}

int	average_index(int index)
{
	int average;

	average = index / 2;
	return (average);
}