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
	int	count;

	count = 1;
	t_stack stack_a;
	t_stack stack_b;
	// t_stack *ptr = NULL;
	t_piece *ptr_piece;
	t_piece *ptr_b;
	t_piece *freeptr;
	t_piece *temp;

	if (ft_check_input(argc, argv) == 1)
		return (0);

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);

	//Create the pieces while fill the stack a
	fill_stack_a(&stack_a, argc, argv);
	//index the pieces
	fill_index(&stack_a, argc, argv);
	if (sorted(&stack_a))
		return 0;
	//sort_three(&stack_a, &stack_b);
	move("rr", &stack_a, &stack_b);

	ptr_b = stack_b.first;
	ptr_piece = stack_a.first;

	if (ptr_piece == NULL)
		printf("No next node(from stack)\n");

	while (ptr_piece != NULL)
	{
		printf("STACK A");
		printf("⚡️PIECE NR. %d:⚡️\n", count);
		printf("VALUE is %d\n", ptr_piece->value);
		printf("INDEX is %d\n", ptr_piece->index);
		ptr_piece = ptr_piece->next;
		count++;
		printf("________________\n");
	}
        printf("No next piece in stack A\n\n\n\n");

    count = 1;
    while (ptr_b != NULL)
	{
		printf("STACK B\n");
		printf("🌸PIECE NR. %d:🌸\n", count);
		printf("VALUE is %d\n", ptr_b->value);
		printf("INDEX is %d\n", ptr_b->index);
		ptr_b = ptr_b->next;
		count++;
		printf("________________\n");
	}
        printf("No next piece in stack B\n");



	//Program the movements

	//Check if all the peices started orderds

	//Reolve
		//REsolve case 2 pieces
		//REsolve case 3 pieces
		//REsolve case 4 pieces
		//REsolve case 5 pieces
		//REsolve other pieces*/
		freeptr = stack_a.first;
		while(freeptr)
		{
			temp = freeptr->next;
			free(freeptr);
			freeptr = temp;
		}


	return (0);
}			
