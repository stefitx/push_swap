/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	free_ptr(t_piece *freeptr)
{
	t_piece	*temp;

	while (freeptr)
	{
		temp = freeptr->next;
		free(freeptr);
		freeptr = temp;
	}
}

int	init_stacks(t_stack	*stack_a, t_stack *stack_b, int argc, char **argv)
{
	initialize_stack(stack_a);
	initialize_stack(stack_b);
	if (fill_stack_a(stack_a, argc, argv) == 0)
		return (0);
	fill_index(stack_a, argc, argv);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_piece	*freeptr;

	if (argc < 2 || ft_check_input(argc, argv) == 1)
		return (0);
	if (init_stacks(&stack_a, &stack_b, argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!sorted(&stack_a))
		check_non_sorted_stack(&stack_a, &stack_b);
	else
		check_sorted_stack();
	freeptr = stack_a.first;
	free_ptr(freeptr);
	return (0);
}
