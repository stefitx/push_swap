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

int	ft_check_input(int argc, char **argv);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int ft_strlen(char *str);
int	ft_strncmp(char *s1, const char *s2, int n);
void initialice_stack(t_stack *stack);
int initial_fill_stack_a(t_stack *stack_a, int argc, char **argv);

#endif


