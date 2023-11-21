/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:31:25 by atudor            #+#    #+#             */
/*   Updated: 2023/11/17 20:31:27 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_a->first->index == biggest_index(stack_a))
		move("ra", stack_a, stack_b);
	if (stack_a->first->next->index == biggest_index(stack_a))
		move("rra", stack_a, stack_b);
	if (stack_a->last->index == biggest_index(stack_a)
		&& !sorted(stack_a))
		move("sa", stack_a, stack_b);
	if (sorted(stack_a))
		return ;
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len <= 5 && stack_a->len >= 4)
	{
		if (stack_a->first->next->index == smallest_index(stack_a))
			move("sa", stack_a, stack_b);
		if (stack_a->first->next->next->index == smallest_index(stack_a))
			move("ra", stack_a, stack_b);
		if ((stack_a->first->next->next->next->index == smallest_index(stack_a)
			|| stack_a->last->index == smallest_index(stack_a)))
			move("rra", stack_a, stack_b);
		if (stack_a->first->index == smallest_index(stack_a)
			&& !sorted(stack_a))
			move("pb", stack_a, stack_b);
		if (sorted(stack_a))
			break ;
	}
	if (stack_a->len == 3)
		sort_three(stack_a, stack_b);
	while (stack_b->len != 0)
		move("pa", stack_a, stack_b);
}

int	sort(int argc, t_stack *stack_a, t_stack *stack_b)
{
if (argc == 3)
		move("sa", stack_a, stack_b);
	else if (argc <= 6)
		small_sort(stack_a, stack_b);
/*	else if (argc >= 6 && argc <= 101)
		sort_five(stack_a, stack_b);
	else if (argc <= 101) // has to be less than 700
	//	sort_hundred(stack_a, stack_b);
	else if (argc > ) // has to be less than 5500
		sort_fivehundred(stack_a, stack_b);
	else if (argc > 501)
		big_sort(stack_a, stack_b);*/

	return 0;
}
