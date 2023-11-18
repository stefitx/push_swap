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

int	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_piece *ptr;

	ptr = stack_a->first;
	if (ptr->index == 0 && ptr->next->index == 2)
		{
			move("pb", stack_a, stack_b);
			move("ra", stack_a, stack_b);
			move("pa", stack_a, stack_b);
		}
	else if (ptr->index == 1 && ptr->next->index == 0)
			move("sa", stack_a, stack_b);
	else if (ptr->index == 1 && ptr->next->index == 2)
			move("rra", stack_a, stack_b);
	else if (ptr->index == 2 && ptr->next->index == 0)
			move("ra", stack_a, stack_b);
	else if (ptr->index == 2 && ptr->next->index == 1)
			{
				move("ra", stack_a, stack_b);
				move("sa", stack_a, stack_b);
			}
return(0);
}

/*int	sort(int argc, t_stack *stack_a, t_stack *stack_b)
{
if (argc == 3)
		do("sa", stack_a, stack_b);
	else if (argc == 4)
		sort_three(stack_a, stack_b);
	else if (argc == 6) //has to be 8 moves
		sort_five(stack_a, stack_b);
	else if (argc <= 101) // has to be less than 700
		sort_hundred(stack_a, stack_b);
	else if (argc <= 501) // has to be less than 5500
		sort_fivehundred(stack_a, stack_b);
	else if (argc > 501)
		big_sort(stack_a, stack_b);

	return 0;
}*/
