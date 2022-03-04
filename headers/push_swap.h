/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:08:05 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/04 03:05:31 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../librairies/libft/libft.h"

# include <stdio.h>

/* MOVES */
# define A 'A'
# define B 'B'
# define R 'R'

typedef struct s_stack	t_stack;

struct s_stack
{
	int		nb;
	t_stack	*next;
};

/* check_args.c */
int		are_valid_args(char **args);

/* get_args.c */
char	**get_args(char **av);

/* is_sort.c */
int		is_sort(t_stack **a);

/* algorithm_three.c */
void	sorting_three(t_stack **a, t_stack **b);

/* algorithm_five.c */
void	sorting_five(t_stack **a, t_stack **b);

/* algorithm_infinity.c */
void	sorting_infinity(t_stack **a, t_stack **b);

/* algorithm_infinity2.c */
void	push_none_lis_to_b(t_stack **a, t_stack **b, int lis_length,
			int *lis);
int		get_last_stack(t_stack *s);
int		get_pos_max(t_stack *s);
void	get_best_mov(int fin_mov[2], int mov[2], t_stack *a, t_stack *b);

/* lis.c */
int		*find_lis(t_stack **a, int *lis_length);

/* rotate_to_min.c */
void	rotate_to_min(t_stack **a, t_stack **b, int t);

/* make_mov.c */
void	make_mov(int find_mov[2], t_stack **a, t_stack **b);

/* instructions.c */
void	sx(t_stack **a, t_stack **b, int move);
void	px(t_stack **a, t_stack **b, int move);
void	rx(t_stack **a, t_stack **b, int move);
void	rrx(t_stack **a, t_stack **b, int move);

/* operations.c */
void	swap(t_stack	**list);
void	push(t_stack	**list_d, t_stack	**list_s);
void	rotate(t_stack	**list);
void	r_rotate(t_stack	**list);

/* create_list.c */
t_stack	*create_elem_list(int nb);
t_stack	*tab_char_to_list(char **av);

/* utils.c */
void	aff_stack(t_stack *stack);
int		len_stack(t_stack *tab);
t_stack	*ft_list_last(t_stack *stack);
t_stack	*ft_stackdup(t_stack *stack);
int		*stack_to_tab(t_stack **a);

/* free.c */
void	free_d_tab(char **tab);
void	free_stack(t_stack	*stack);

/* errors.c */
void	error(void);

#endif
