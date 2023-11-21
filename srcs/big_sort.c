/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:24:33 by atudor            #+#    #+#             */
/*   Updated: 2023/11/21 17:25:10 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	initial_divide(t_stack *stack_a, t_stack *stack_b)
{
	int general_average;
	int count;

	count = stack_a->len;
	general_average = average(stack_a);
	while (count != 0)
	{
		if (stack_a->first->index > general_average)
			move("pb", stack_a, stack_b);
		else
			move("ra", stack_a, stack_b);
		count--;
	}
}

int	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	initial_divide(stack_a, stack_b);
// 	/*if (stack_a->first->index > stack_a->last->index
// 		&& stack_b->first->index < stack_b->last->index)
// 		move("rr", stack_a, stack_b);
// 	if (stack_a->first->index > stack_a->first->next->index
// 		&& stack_b->first->index < stack_b->first->next->index)
// 		move("ss", stack_a, stack_b);

// while (!sorted(stack_a))
// {
// 		if (stack_a->first->index > stack_a->last->index
// 			&& stack_b->first->index > stack_b->last->index)
// 			move("ra", stack_a, stack_b);
		
// 		if (stack_a->first->index > stack_a->first->next->index
// 			&& stack_b->first->index > stack_b->first->next->index)
// 			move("sa", stack_a, stack_b);
		
// 		if (stack_a->first->index > stack_a->last->index
// 			&& stack_b->first->index > stack_b->last->index)
// 			move("rra", stack_a, stack_b);
// 		else
// 			break ;
// }
// while (!sorted(stack_b))
// {
// 		if (stack_a->first->index < stack_a->last->index
// 			&& stack_b->first->index < stack_b->last->index
// 			&& stack_b->first->index > stack_b->first->next->index)
// 			move("rb", stack_a, stack_b);
// 		if (stack_a->first->index < stack_a->first->next->index
// 			&& stack_b->first->index < stack_b->first->next->index 
// 			&& stack_b->last->index > stack_b->first->index)
// 			move("sb", stack_a, stack_b);
// 		if (stack_a->first->index < stack_a->last->index
// 			&& stack_b->first->index > stack_b->last->index
// 			&& stack_b->first->index < stack_b->first->next->index)
// 			move("rrb", stack_a, stack_b);
// 		else
// 			break;
// }
// 		/*while (!(sorted(stack_b)))
// 		{
// 			if(stack_b->first->index < stack_a->first->index)
// 				move("pa", stack_a, stack_b);
// 		}*/



	return 0;
}