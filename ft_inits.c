/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:10:21 by atudor            #+#    #+#             */
/*   Updated: 2023/11/05 17:12:15 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int add_piece_to_stack(t_stack *stack, t_piece *new_piece)
{

}

// for every argv (starting by 1), we will create a new piece (whit malloc)
// then we will place this peace to the stack
int initial_fill_stack_a(t_stack *stack_a, int argc, char **argv)
{	
	t_piece *new_piece;

	while()
	{
		new_piece = malloc(sizeof(t_piece * 1));
		//give the value to the piexe
		//add_the_piece_to_stack
	}

}

//Will place the initial values of a stack
void initialice_stack(t_stack *stack)
{
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}
