/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:56 by atudor            #+#    #+#             */
/*   Updated: 2023/11/23 16:32:59 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	chunk(int argc)
{
	//int	chunks;

	/*if (argc > 6 && argc < 102)
		chunks = 6;
	if (argc >= 102)
		chunks = 7 + ((argc - 100) / 100);*/

	if (argc <= 101)
		return(4);
	return 8;
	//return (chunks);
}

void	chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	int chunk_len;
	int current_chunk;
	int	count;

	chunk_len = stack_a->len / chunks;
	current_chunk = chunk_len;
	while (stack_a->len != 0)
	{
		count = stack_a->len;
		while (count > 0)
		{
			if (stack_a->first->index <= current_chunk)
			{
				move("pb", stack_a, stack_b);
				if(stack_b->first->index  > (current_chunk - chunk_len/2))
					move("rb", stack_a, stack_b);
			}
			else
				move("ra", stack_a, stack_b);
			count--;
			/*if (which_move('b', current_chunk, stack_a) == -1)
				break ;
			else if (which_move('b', current_chunk, stack_a) < (stack_a->len / 2))
				move("ra", stack_a, stack_b);
			else if (which_move('b', current_chunk, stack_a) >= (stack_a->len / 2))
				move("rra", stack_a, stack_b);*/
			
		}
	current_chunk += chunk_len;
	}
}

int  is_premoved(int index, t_stack *stack_a)
{
	if (stack_a->len < 2)
		return (0);
	if (stack_a->first->next->index == index)
		return (1);
	return (0);
}

void	order_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	biggest_in;
	
	count = stack_b->len - 1;;
	while (count >= 0)
	{
		biggest_in = count;
		if(is_premoved(biggest_in, stack_a))
		{
			move("sa", stack_a, stack_b);
			count--;
			continue ;
		}
		if(stack_b->first->index == biggest_in -1)
		{
			move("pa", stack_a, stack_b);
		}
		if (stack_b->first->index == biggest_in && biggest_in != 0)
		{
			move("pa", stack_a, stack_b);
			count--;
		}
		else if(stack_b->first->index != biggest_in)
		{
			if (which_move('a', biggest_index(stack_b), stack_b) < (stack_b->len / 2))
				move("rb", stack_a, stack_b);
			if (which_move('a', biggest_index(stack_b), stack_b) >= (stack_b->len / 2))
				move("rrb", stack_a, stack_b);
		}
		else if (stack_b->first->index == biggest_in && biggest_in == 0)
		{
			move("pa", stack_a, stack_b);
			count--;
		}
	}
}

void	chunks_sort(int argc, t_stack *stack_a, t_stack *stack_b)
{
	int	chunks;

	chunks = chunk(argc);
	chunks_to_b(stack_a, stack_b, chunks);
	order_to_a(stack_a, stack_b);
}