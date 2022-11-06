/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:27:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/11/06 20:44:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lorem_ipsum.h"
#include "t_int.h"
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char const *str);

int	main(void)
{
	char const *const	strings[] = {
		"",
		"A",
		"bb",
		"CCC",
		LOREM_128,
		LOREM_256,
		LOREM_512,
		LOREM_1024,
		LOREM_2048,
		LOREM_4096,
		LOREM_8192,
		LOREM_16384,
		LOREM_32768,
		LOREM_65536,
		NULL
	};
	t_uint	idx;

	for (idx = 0U ; strings[idx] ; ++idx)
		if (ft_strlen(strings[idx]) != strlen(strings[idx]))
			return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
