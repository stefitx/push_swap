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

#include "../includes/ft_push_swap.h"

void	swap(t_stack *stack)
{
	t_piece	*first_ptr;
	t_piece	*second_ptr;

	if (stack->len < 2)
		return ;
	first_ptr = stack->first;
	second_ptr = stack->first->next;
	first_ptr->next = second_ptr->next;
	stack->first = second_ptr;
	second_ptr->next = first_ptr;
	if (stack->len == 2)
		stack->last = first_ptr;
}

void	push(t_stack *sender, t_stack *receiver)
{
	t_piece	*first_ptr;
	t_piece	*second_ptr;

	if (sender->len == 0)
		return ;
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
}

void	rotate(char *s, t_stack *stack)
{
	t_piece	*first_ptr;
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
	else if (ft_strncmp(s, "reverse", 7) == 0)
	{
		stack->first = before_last_ptr->next;
		before_last_ptr->next = NULL;
		stack->first->next = first_ptr;
		stack->last = before_last_ptr;
	}
}

void	simultaneous(char *s, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(s, "swap", 6) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(s, "rotate", 6) == 0)
	{
		rotate("rotate", stack_a);
		rotate("rotate", stack_b);
	}
	else if (ft_strncmp(s, "reverse", 7) == 0)
	{
		rotate("reverse", stack_a);
		rotate("reverse", stack_b);
	}
}

void	move(char *s, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(s, "sa", 2) == 0)
		swap(stack_a);
	else if (ft_strncmp(s, "sb", 2) == 0)
		swap(stack_b);
	else if (ft_strncmp(s, "ss", 2) == 0)
		simultaneous("swap", stack_a, stack_b);
	else if (ft_strncmp(s, "pa", 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(s, "pb", 2) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(s, "ra", 2) == 0)
		rotate("rotate", stack_a);
	else if (ft_strncmp(s, "rb", 2) == 0)
		rotate("rotate", stack_b);
	else if (ft_strncmp(s, "rra", 3) == 0)
		rotate("reverse", stack_a);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		rotate("reverse", stack_b);
	else if (ft_strncmp(s, "rrr", 3) == 0)
		simultaneous("reverse", stack_a, stack_b);
	else if (ft_strncmp(s, "rr", 2) == 0)
		simultaneous("rotate", stack_a, stack_b);
	printf("%s\n", s);
}
