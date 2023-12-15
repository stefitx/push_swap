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
	t_piece	*ptr;
	int		index;

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
	t_piece	*ptr;
	int		index;

	if (stack->len == 0)
		return (-1);
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

int	chunk(int argc)
{
	if (argc <= 101)
		return (4);
	return (8);
}

int	w_m(char x, int given_index, t_stack *stack)
{
	t_piece	*ptr;
	int		count;

	count = 0;
	ptr = stack->first;
	if (x == 'a')
	{
		while (ptr->index != given_index)
		{
			count++;
			ptr = ptr->next;
		}
	}
	if (x == 'b')
	{
		while (ptr && ptr->index > given_index)
		{
			count++;
			ptr = ptr->next;
		}
		if (!ptr || (ptr->index > given_index && count == stack->len))
			return (-1);
	}
	return (count);
}
