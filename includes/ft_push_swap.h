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

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_piece
{
	int				value;
	int				index;
	struct s_piece	*next;
}	t_piece;

typedef struct s_stack
{
	int		len;
	t_piece	*first;
	t_piece	*last;
}	t_stack;

int		main(int argc, char **argv);
int		ft_check_input(int argc, char **argv);
int		if_no_error(int error, int i, int j, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, const char *s2, int n);
void	initialize_stack(t_stack *stack);
int		fill_stack_a(t_stack *stack_a, int argc, char **argv);
int		fill_index(t_stack *stack, int argc, char **argv);
void	swap(t_stack *stack);
void	push(t_stack *sender, t_stack *receiver);
void	rotate(char *s, t_stack *stack);
void	simultaneous(char *s, t_stack *stack_a, t_stack *stack_b);
void	move(char *s, t_stack *stack_a, t_stack *stack_b);
int		sorted(t_stack *stack);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
void	small_sort(t_stack *stack_a, t_stack *stack_b);
int		sort(int argc, t_stack *stack_a, t_stack *stack_b);
int		smallest_index(t_stack *stack);
int		biggest_index(t_stack *stack);
int		big_sort(t_stack *stack_a, t_stack *stack_b);
void	order_to_a(t_stack *stack_a, t_stack *stack_b);
void	chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunks);
int		chunk(int argc);
void	chunks_sort(int argc, t_stack *stack_a, t_stack *stack_b);
int		w_m(char x, int index, t_stack *stack);
int		ft_strcmp(char *s1, const char *s2);
void	check_non_sorted_stack(t_stack	*stack_a, t_stack *stack_b);
void	evaluate_final_result(t_stack	*stack_a, t_stack *stack_b);
void	check_sorted_stack(void);
int		is_correct_movement(char *s);
#endif
