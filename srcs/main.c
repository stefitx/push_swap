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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_piece	*freeptr;
	t_piece	*temp;

	if (argc < 2 || ft_check_input(argc, argv) == 1)
		return (0);
	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
	fill_stack_a(&stack_a, argc, argv);
	fill_index(&stack_a, argc, argv);
	if (!sorted(&stack_a))
		sort(argc, &stack_a, &stack_b);
	freeptr = stack_a.first;
	while (freeptr)
	{
		temp = freeptr->next;
		free(freeptr);
		freeptr = temp;
	}
	return (0);
}
