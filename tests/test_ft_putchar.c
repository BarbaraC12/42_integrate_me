/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:34:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/08 10:08:59 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_putchar(char const c);

int	main(void)
{
	char	c;
	char	buff[1];
	int		fd[2];
	size_t	ret;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return EXIT_FAILURE;
	}

	close(STDOUT_FILENO);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(fd[0]);
		close(fd[1]);
		return EXIT_FAILURE;
	}

	for (c = CHAR_MIN ; c < CHAR_MAX ; ++c)
	{
		ret = ft_putchar(c);
		if (ret != 1)
		{
			close(fd[0]);
			close(fd[1]);
			return EXIT_FAILURE;
		}
		if (read(fd[0], buff, 1LU) == -1)
		{
			perror("read");
			close(fd[0]);
			close(fd[1]);
			return EXIT_FAILURE;
		}
		else if (c != *buff)
		{
			close(fd[0]);
			close(fd[1]);
			return EXIT_FAILURE;
		}
	}

	if ((close(fd[0]) | close(fd[1])) == -1)
	{
		perror("close");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
