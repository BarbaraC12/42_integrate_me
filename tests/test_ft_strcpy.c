/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:12:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/06 21:06:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_test	t_test;

struct s_test
{
	char const		*src;
	char *const		dst0;
	char *const		dst1;
	size_t const	size;
};

char	*ft_strcpy(char *dst, char const *src);

int	main(void)
{
	t_test const	tests[] = {
		{
			(char []){0, 'N', 'o', 't', 'h', 'i', 'n', 'g'},
			(char []){'3', '2', '1', 0, '#', '$', '%', '@', '!'},
			(char []){'3', '2', '1', 0, '#', '$', '%', '@', '!'},
			9LU
		},
		{
			(char []){'W', 'h', 'a', 't', 's', ' ', 'u', 'p', 0},
			(char []){'H', 'i', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', '.', '.', '.'},
			(char []){'H', 'i', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', '.', '.', '.'},
			13LU
		},
		{
			(char []){'f', 'z', 'e', 'r', 'o', 0, 'd', 'o', 'o', 'm'},
			(char []){'k', 'o', 'a', 'l', 'a', 0, 'k', 'i', 'n', 'g', ' ', 'f', 'o',
			'r', 'e', 'v', 'e', 'r', 0},
			(char []){'k', 'o', 'a', 'l', 'a', 0, 'k', 'i', 'n', 'g', ' ', 'f', 'o',
			'r', 'e', 'v', 'e', 'r', 0},
			19LU
		},
		{
			(char []){'B', 'e', ' ', 'h', 'a', 'p', 'p', 'y', 0},
			(char []){'D', 'o', 'n', 't', ' ', 'w', 'o', 'r', 'r', 'y', ' ', 0, 'D',
			'a', 'n', 's', 'e', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'e', 0},
			(char []){'D', 'o', 'n', 't', ' ', 'w', 'o', 'r', 'r', 'y', ' ', 0, 'D',
			'a', 'n', 's', 'e', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'e', 0},
			26LU
		},
		{
			(char []){'A', 'B', 'B', 'A', 0, 0, 0, 0},
			(char []){'H', 'e', 'l', 'l', 'o', ' ', 'd', 'a', 'r', 'k', 'n', 'e', 's',
			's', ',', ' ', 'm', 'y', ' ', 'o', 'l', 'd', 'f', 'r', 'i', 'e', 'n', 'd',
			0, 'I', '\'', 'v', 'e', ' ', 'c', 'o', 'm', 'e', ' ', 'n', 'o', 'w'},
			(char []){'H', 'e', 'l', 'l', 'o', ' ', 'd', 'a', 'r', 'k', 'n', 'e', 's',
			's', ',', ' ', 'm', 'y', ' ', 'o', 'l', 'd', 'f', 'r', 'i', 'e', 'n', 'd',
			0, 'I', '\'', 'v', 'e', ' ', 'c', 'o', 'm', 'e', ' ', 'n', 'o', 'w'},
			42LU
		},
		{
			(char []){'P', 'r', 'o', 'g', 'r', 'a', 'm', ' ', 'i', 'n', ' ', 'C', ' ',
			'!', ' ', 'A', 'n', 'd', ' ', 'b', 'e', 'c', 'o', 'm', 'e', ' ', 'a', ' ',
			't', 'r', 'u', 'e', ' ', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'p', 'e', 'r',
			0},
			(char []){0, 'J', 'a', 'v', 'a', ' ', 'i', 's', ' ', 'n', 'o', 't', ' ',
			's', 'o', ' ', 'b', 'a', 'd', ',', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a',
			'l', 'l', '.', '.', '.', ' ', 'D', 'o', 'n', 't', ' ', 'y', 'o', 'u', ' ',
			'a', 'g', 'r', 'e', 'e', ' ', '?'},
			(char []){0, 'J', 'a', 'v', 'a', ' ', 'i', 's', ' ', 'n', 'o', 't', ' ',
			's', 'o', ' ', 'b', 'a', 'd', ',', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a',
			'l', 'l', '.', '.', '.', ' ', 'D', 'o', 'n', 't', ' ', 'y', 'o', 'u', ' ',
			'a', 'g', 'r', 'e', 'e', ' ', '?'},
			50LU
		},
		{
			(char []){'T', 'a', 'k', 'e', ' ', 'o', 'n', ' ', 'm', 'e', 0},
			(char []){'N', 'e', 'v', 'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'g',
			'i', 'v', 'e', ' ', 'y', 'o', 'u', ' ', 'u', 'p', '.', 0, 'N', 'e', 'v',
			'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'l', 'e', 't', ' ', 'y', 'o',
			'u', ' ', 'd', 'o', 'w', 'n', '.', 0},
			(char []){'N', 'e', 'v', 'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'g',
			'i', 'v', 'e', ' ', 'y', 'o', 'u', ' ', 'u', 'p', '.', 0, 'N', 'e', 'v',
			'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'l', 'e', 't', ' ', 'y', 'o',
			'u', ' ', 'd', 'o', 'w', 'n', '.', 0},
			51LU
		},
		{0}
	};
	char	*dst0;
	char	*dst1;
	t_uint	idx;

	for (idx = 0U ; tests[idx].src ; ++idx)
	{
		dst0 = strcpy(tests[idx].dst0, tests[idx].src);
		dst1 = ft_strcpy(tests[idx].dst1, tests[idx].src);

		if (dst0 - tests[idx].dst0 != dst1 - tests[idx].dst1 ||
			memcmp(tests[idx].dst0, tests[idx].dst1, tests[idx].size))
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
