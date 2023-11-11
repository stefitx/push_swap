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
	if (stack->len == 0 && stack->first == NULL)
	{
		stack->first = new_piece;
		stack->len += 1;
		stack->last = new_piece;
	}
}

int fill_stack_a(t_stack *stack_a, int argc, char **argv)
{	
	t_piece *new_piece;
	int	i;

	i = 1;
	while(i <= argc)
	{
		new_piece = malloc(sizeof(t_piece * 1));
		new_piece->value = (ft_atoi(argv[i++]));
		add_the_piece_to_stack(stack_a, new_piece);
	}

}

void initialize_stack(t_stack *stack)
{
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}
