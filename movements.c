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

int	swap(t_stack *stack)
{
	t_piece	*first_ptr;
	t_piece	*second_ptr;


	if (stack->len < 2)
        return 0;
	first_ptr = stack->first; // == (*stack).first
	second_ptr = stack->first->next; // *((*stack).first).next
	first_ptr->next = second_ptr->next;
	stack->first = second_ptr;
	second_ptr->next = first_ptr;

	if (stack->len == 2)
		stack->last = first_ptr;
return 0;
}

int	push(t_stack *sender, t_stack *receiver)
{
	t_piece	*first_ptr;
	t_piece	*second_ptr;

	if (sender->len == 0)
		return 0;
	first_ptr = sender->first;
	second_ptr = receiver->first;
	sender->first = sender->first->next;
	receiver->first = first_ptr;
	receiver->first->next = second_ptr;
	sender->len -= 1;
	receiver->len += 1;

	if (sender->len == 1)
		sender->last = sender->first;
	if (receiver->len == 1)
		receiver->last = receiver->first;
	if (sender->len == 0)
		sender->last = NULL;
return 0;
}

void	rotate(char *s, t_stack *stack)
{
	t_piece *first_ptr;
	t_piece	*before_last_ptr;

	if (stack->len < 2)
	    return ;
	first_ptr = stack->first;
	before_last_ptr = stack->first;
	while (before_last_ptr->next->next != NULL)
		before_last_ptr = before_last_ptr->next;
	if (ft_strncmp(s, "rotate", 6) == 0)
	{
	stack->first = stack->first->next;
	before_last_ptr->next->next = first_ptr;
	before_last_ptr->next->next->next = NULL;
	stack->last = first_ptr;
	}
	if (ft_strncmp(s, "reverse", 7) == 0)
	{
		stack->first = before_last_ptr->next;
		before_last_ptr->next = NULL;
		stack->first->next = first_ptr;
		stack->last = before_last_ptr;
	}
}

int	simultaneous(char *s, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(s, "swap", 6) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (ft_strncmp(s, "rotate", 6) == 0)
	{
		rotate("rotate", stack_a);
		rotate("rotate", stack_b);
	}
	if (ft_strncmp(s, "reverse", 6) == 0)
	{
		rotate("reverse", stack_a);
		rotate("reverse", stack_b);
	}
	return 0;
}

// ss (do swap for both stacks)
// pa(from b to a) & pb(from a o b) (push from top of one stack to top of other stack, do nothing if the pusher is empty)
// ra & rb (rotate first and last pieces in stack)
// rr (rotate both stacks at the same time (1st becomes last))
// rra & rrb & rrr (last becomes first)
