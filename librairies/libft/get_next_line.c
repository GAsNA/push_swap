/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:48:26 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/09 10:21:13 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 1

static int	get_read(int fd, char **mem)
{
	int		size;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	size = 1;
	while (!ft_strchr(*mem, '\n') && size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1 || size == 0)
		{
			free(buf);
			return (0);
		}
		buf[size] = '\0';
		*mem = ft_strjoin(*mem, buf);
	}
	free(buf);
	return (size);
}

static char	*get_line(char **str, char **mem)
{
	char	*tmp;
	int		n;

	n = 0;
	tmp = *mem;
	while ((*mem)[n] != '\n' && (*mem)[n] != '\0')
		n++;
	if (ft_strchr(*mem, '\n'))
	{
		*str = ft_substr(*mem, 0, n + 1);
		*mem = ft_strdup(*mem + n + 1);
	}
	else
	{
		*str = ft_strdup(tmp);
		*mem = 0;
		free(*mem);
	}
	free(tmp);
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*str;
	int			size;

	if (fd < 0 || fd > 1025 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, "", 0) == -1)
		return (0);
	if (!mem)
		mem = ft_strdup("");
	size = get_read(fd, &mem);
	if ((size == 0 && !mem[0]) || size == 0)
	{
		free(mem);
		return (0);
	}
	get_line(&str, &mem);
	return (str);
}

/*int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		fd2;

	(void) ac;
//	(void) av;
	fd = open(av[1], O_RDONLY);
	fd2 = 55555;
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	while ((str = get_next_line(fd2)))
	{
		printf("%s", str);
		free(str);
	}
	return (0);
}*/
