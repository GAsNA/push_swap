/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:07:00 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/08 16:43:52 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nb_args(char **av)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	len = 0;
	i = -1;
	while (av[++i])
	{
		if (ft_strchr(av[i], ' '))
		{
			tmp = ft_split(av[i], ' ');
			j = -1;
			while (tmp[++j])
				len++;
			free_d_tab(tmp);
		}
		else
			len++;
	}
	return (len);
}

static void	distribution_str(char **av, int i, int *j, char **ret)
{
	int		k;
	char	**tmp;

	if (ft_strchr(av[i], ' '))
	{
		tmp = ft_split(av[i], ' ');
		k = -1;
		while (tmp[++k])
		{
			ret[*j] = ft_strdup(tmp[k]);
			(*j)++;
		}
		free_d_tab(tmp);
	}
	else
	{
		ret[*j] = ft_strdup(av[i]);
		(*j)++;
	}
}

static char	**get_args(char **av)
{
	int		i;
	int		j;
	char	**ret;

	ret = malloc((get_nb_args(av) + 1) * sizeof(char *));
	if (!ret)
		exit(0);
	i = 0;
	j = 0;
	while (av[++i])
		distribution_str(av, i, &j, ret);
	ret[j] = 0;
	return (ret);
}

int	main(int ac, char **av)
{
	char	**args_char;
	t_stack	*a;
	t_stack	*b;
	t_stack *a_t;
	t_stack	*b_t;

	args_char = get_args(av);
	if (ac == 1 || !are_valid_args(args_char))
		error();
	else
	{
		a = tab_char_to_list(args_char);
		b = 0;
		sorting_three(&a, &b);
		a_t = a;
		b_t = b;
		while (a)
		{
			printf("%i | ", a->nb);
			a = a->next;
		}
		printf("\n");
		while (b)
		{
			printf("%i | ", b->nb);
			b = b->next;
		}
		free_stack(a_t);
		free_stack(b_t);
	}
	free_d_tab(args_char);
	return (0);
}
