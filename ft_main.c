/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{

	t_stack stack_a;
	t_stack stack_b;
	t_stack *ptr = NULL;
	t_piece *ptr_piece = NULL;

	if (ft_check_input(argc, argv) == 1)
		return (0);

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);

	//Create the pieces while fill the stack a
	fill_stack_a(&stack_a, argc, argv);

	//print stack a , pieces iterating from first , piece by biece
	while (stack_a)
	{
		ptr = stack_a;
		ptr_p = stack_a->first;
		printf("%d", ptr_p->data);
	}
	//printf("%d -> ", stack_a->data)






	//calcualte the indexes of the pieces

	//Program the movements

	//Check if all the peices started orderds

	//Reolve
		//REsolve case 2 pieces
		//REsolve case 3 pieces
		//REsolve case 4 pieces
		//REsolve case 5 pieces
		//REsolve other pieces*/
	return (0);
}			
