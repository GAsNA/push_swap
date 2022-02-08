/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:08:05 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/08 16:42:50 by rleseur          ###   ########.fr       */
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
typedef struct t_inst	t_inst;

struct s_stack
{
	int		nb;
	t_stack	*next;
};

/* check_args.c */
int		are_valid_args(char **args);

/* algorithm_three.c */
void	sorting_three(t_stack **a, t_stack **b);

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
int		len_stack(t_stack *tab);

/* free.c */
void	free_d_tab(char **tab);
void	free_stack(t_stack	*stack);

/* errors.c */
void	error(void);

#endif
