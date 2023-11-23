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
		if (stack_a->first->index <= general_average)
			move("pb", stack_a, stack_b);
		else
			move("ra", stack_a, stack_b);
		count--;
	}
}

//if (distance(stack_a->first->index, biggest_index(stack_a)) >  

void	internal_divide(t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = stack_b->len;
	count *= 3;
	while (count != 0)
	{
		if (stack_a->first->index > average(stack_a)
			&& stack_b->first->index < average(stack_b))
			move("rr", stack_a, stack_b);

		if (stack_a->first->index > average(stack_a)
			&& stack_b->first->index > average(stack_b)
			&& stack_b->first->index < stack_b->first->next->index)
		{
			move("sb", stack_a, stack_b);
			move("rrb", stack_a, stack_b);
		}

		if (stack_b->first->index < average(stack_b)
			&& stack_a->first->index < average(stack_a)
			&& stack_a->first->index > stack_a->first->next->index)
		{
			move("sa", stack_a, stack_b);
			move("rra", stack_a, stack_b);
		}

		if (stack_a->last->index < average(stack_a)
			&& stack_b->last->index > average(stack_b))
			move("rrr", stack_a, stack_b);
		count--;
	}
}

void	tandem(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->first->next->index > stack_a->first->index
		&& stack_a->first->next->index > stack_a->last->index
		&& stack_b->first->next->index < stack_b->first->index
		&& stack_b->first->next->index < stack_b->last->index)
		|| (stack_a->last->index > stack_a->first->index
		&& stack_a->last->index > stack_a->first->next->index
		&& stack_b->last->index < stack_b->first->index
		&& stack_b->last->index < stack_b->first->next->index))
	// if biggest / smallest is the second number
		move("ss", stack_a, stack_b);
	if (stack_a->first->index > stack_a->first->next->index
		&& stack_a->first->index > stack_a->last->index
		&& stack_b->first->index < stack_b->first->next->index
		&& stack_b->first->index < stack_b->last->index)
		move("rr", stack_a, stack_b);
	if (stack_a->last->index < stack_a->first->index
		&& stack_b->last->index > stack_b->first->index)
		move("rrr", stack_a, stack_b);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int count;

	count = stack_b->len;
	while (count > 0)
	{
	while (stack_b->first->index > stack_b->last->index
		|| stack_b->first->index > stack_b->first->next->index)
		move("rb", stack_a, stack_b);
	if (stack_b->first->next->index > stack_b->first->index)
		move("sb", stack_a, stack_b);
	else
	{
		break ;
		//move("rb", stack_a, stack_b);
	}
	count--;
	}
}

void	sort_three_mod(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_b->len == 3)
	{
	if (stack_b->first->index == biggest_index(stack_b))
		move("rb", stack_a, stack_b);
	if (stack_b->first->next->index == biggest_index(stack_b))
		move("rrb", stack_a, stack_b);
	if (stack_b->last->index == biggest_index(stack_b)
		&& !sorted(stack_a))
		move("sb", stack_a, stack_b);
	if (sorted(stack_b))
		return ;
	}
	/*if (stack_b->len == 4)
		{
	if (stack_b->first->index == biggest_index(stack_b))
		move("rb", stack_a, stack_b);
	if (stack_b->first->next->index == biggest_index(stack_b))
		move("rrb", stack_a, stack_b);
	if (stack_b->last->index == biggest_index(stack_b)
		&& !sorted(stack_a))
		move("sb", stack_a, stack_b);
	if (sorted(stack_b))
		return ;
	}*/
}

void	second_divide(t_stack *stack_a, t_stack *stack_b)
{
	int average;
	int count;
	int	rra;

	rra = 0;
	count = stack_b->len;
	average = (smallest_index(stack_b) + biggest_index(stack_b)) / 2;

	while (count != 0)
		{
		if (stack_b->first->index >= average)
			move("pa", stack_a, stack_b);
		else
			move("rb", stack_a, stack_b);
		count--;
	}
	count = stack_b->len;
	while (count != 0)
	{
		if (stack_a->first->index <= average)
			move("pb", stack_a, stack_b);
		else
		{
			move("ra", stack_a, stack_b);
			rra++;
		}
		count--;
	}
	while (rra != 0)
	{
		move("rra", stack_a, stack_b);
		rra--;
	}
	sort_b(stack_a, stack_b);
	sort_three_mod(stack_a, stack_b);

}

// void move_in_x_chunks_to_b(int num_chunks, t_stack *stack_a, t_stack *stack_b)
// {
// 	//total of pieces
// 	//cunk_len = total of pieces / num_chunks
// }

int	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	initial_divide(stack_a, stack_b);
	internal_divide(stack_a, stack_b);
	tandem(stack_a, stack_b);
	sort_b(stack_a, stack_b);
	second_divide(stack_a, stack_b);
	second_divide(stack_a, stack_b);
	second_divide(stack_a, stack_b);
	second_divide(stack_a, stack_b);
	//second_divide(stack_a, stack_b);
	//move("pb", stack_a, stack_b);
	//sort_three_mod(stack_a, stack_b);

	// while(!sorted(stack_b))
	// {
	// 	if (stack_b->first->index < stack_b->first->next->index)
	// 		move("rb", stack_a, stack_b);
	// 	if (stack_b->first->next->index < stack_b->last->index)
	// 	{
	// 		move("sb", stack_a, stack_b);
	// 		move("rb", stack_a, stack_b);
	// 	}
	// 	else
	// 		break ;
	// }
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