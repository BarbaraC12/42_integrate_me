/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:34:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/06 18:41:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char const c);

int	main(void)
{
	char	c;
	char	buff[1];
	int		fd[2];

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
		ft_putchar(c);
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
