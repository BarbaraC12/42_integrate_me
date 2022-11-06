/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:58:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/06 20:44:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char const *str);

static int	__test_one(char const *const str, int const *const fd)
{
	size_t const	len = strlen(str);
	char			*buff;
	ssize_t			rd;

	ft_putstr(str);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
	{
		perror("malloc");
		return EXIT_FAILURE;
	}

	rd = read(fd[0], buff, len);
	if (rd == -1)
	{
		free(buff);
		perror("read");
		return EXIT_FAILURE;
	}
	buff[rd] = 0;
	if (strcmp(str, buff))
	{
		free(buff);
		return EXIT_FAILURE;
	}
	free(buff);
	return EXIT_SUCCESS;
}

int	main(void)
{
	char const *const	strings[] = {
		"",
		"koala",
		"g",
		"42 est une ecole grandiose !",
		"\t\n\n\t",
		"D0n't w0rry, b3 h4ppy",
		"AhKuNa MaTaTa!@#$%^&*()",
		"\x12\x99\xaa",
		"fcuf873t9R%*QYDOHCH*(W@(*bvjb66++",
		NULL
	};
	int					fd[2];
	t_uint				idx;

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

	for (idx = 0U ; strings[idx] ; ++idx)
		if (__test_one(strings[idx], fd))
			return EXIT_FAILURE;

	if (close(fd[0]) == -1 || close(fd[1]) == -1)
	{
		perror("close");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
