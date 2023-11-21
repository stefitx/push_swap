/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct s_piece
{
	int	value;
	int	index;
	struct	s_piece *next;
}	t_piece;

typedef	struct s_stack
{
	int	len;
	t_piece	*first;
	t_piece	*last;
}	t_stack;

int	main(int argc, char **argv);
int	ft_check_input(int argc, char **argv);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int ft_strlen(char *str);
int	ft_strncmp(char *s1, const char *s2, int n);
void initialize_stack(t_stack *stack);
int fill_stack_a(t_stack *stack_a, int argc, char **argv);
int	fill_index(t_stack *stack, int argc, char **argv);
void	swap(t_stack *stack);
void	push(t_stack *sender, t_stack *receiver);
void	rotate(char *s, t_stack *stack);
void	simultaneous(char *s, t_stack *stack_a, t_stack *stack_b);
void	move(char *s, t_stack *stack_a, t_stack *stack_b);
int	sorted(t_stack *stack);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
void	small_sort(t_stack *stack_a, t_stack *stack_b);
int	sort(int argc, t_stack *stack_a, t_stack *stack_b);
int	smallest_index(t_stack *stack);
int	biggest_index(t_stack *stack);
int	big_sort(t_stack *stack_a, t_stack *stack_b);
int	average_index(int index);
int average(t_stack *stack);

#endif

/*void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len == 4)
	{
		if (stack_a->first->next->index == smallest_index(stack_a) 
			&& !sorted(stack_a))
			move("ra", stack_a, stack_b);
		if ((stack_a->first->next->next->index == 1
			|| stack_a->last->index == smallest_index(stack_a)) && !sorted(stack_a))
			move("rra", stack_a, stack_b);
		if ((stack_a->first->index == 1) && !sorted(stack_a))
			move("pb", stack_a, stack_b);
		if (sorted(stack_a))
			return ;
	}
	if (stack_a->len == 3)
		sort_three(stack_a, stack_b);
	if (!sorted(stack_a))
			sort_four(stack_a, stack_b);*/

/*2 0 1
2 1 0

0 2 1
1 2 0

1 0 2

		if (stack_a->first->index < stack_a->last->index
			&& stack_b->first->index > stack_b->last->index)
			move("rrr", stack_a, stack_b);










1 0 2
2 0 1

0 2 1

2 1 0
1 2 0*/