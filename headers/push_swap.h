/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:08:05 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/02 14:50:07 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../librairies/libft/libft.h"

# include <stdio.h>

/* check_args.c */
int		are_valid_args(char **args);

/* utils.c */
int		len_tab_int(int	*tab);
int		*duplicate_tab_int(int *tab);

/* free.c */
void	free_d_tab(char **tab);

/* errors.c */
void	error(void);

#endif
