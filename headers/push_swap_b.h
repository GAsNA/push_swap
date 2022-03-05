/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:01:16 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 05:22:55 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_B_H
# define PUSH_SWAP_B_H

# include <stdio.h>
# include <unistd.h>

# include "../librairies/libft/libft.h"

typedef struct s_stack	t_stack;

struct s_stack
{
	int		nb;
	t_stack	*next;
};

/* get_args.c */
char	**get_args(char **av);

/* check_args.c */
int		are_valid_args(char **args);

/* actions.c */
void	actions(t_stack **a, t_stack **b);

/* operations.c */
void	swap(t_stack **list);
void	push(t_stack **list_d, t_stack **list_s);
void	rotate(t_stack **list);
void	r_rotate(t_stack **list);

/* utils.c */
int		len_stack(t_stack *stack);
void	aff_stack(t_stack *stack);
t_stack	*ft_list_last(t_stack *stack);
t_stack	*ft_stackdup(t_stack *stack);
int		*stack_to_tab(t_stack **a);
int		is_sort(t_stack **a);

/* create_list.c */
t_stack	*create_elem_list(int nb);
t_stack	*tab_char_to_list(char **av);

/* write.c */
int		error(void);
void	ok(void);
void	ko(void);

/* free.c */
void	free_d_tab(char **tab);
void	free_stack(t_stack *stack);

#endif
