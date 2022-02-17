/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:36:23 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/09 13:37:31 by rleseur          ###   ########.fr       */
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

char	**get_args(char **av)
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
