/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	delete(t_piece *del)
{
	del->value = 0;
	del->index = 0;
	del->next = NULL;
	return 0;
}

int	swap(t_stack *stack)
{
	t_piece	*first;
	t_piece	*second;


	if (stack->len < 2)
        return 0;
	first = stack->first; // == (*stack).first
	second = stack->first->next; // *((*stack).first).next
	first->next = second->next;
	stack->first = second;
	second->next = first;

	if (stack->len == 2)
		stack->last = first;
return 0;
}

// ss (do swap for both stacks)
// pa & pb (push from top of one stack to top of other stack, do nothing if the pusher is empty)
// ra & rb (rotate first and last pieces in stack)
// rr (rotate both stacks at the same time (1st becomes last))
// rra & rrb & rrr (last becomes first)
