/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/07/28 16:56:17 by ███████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_calloc(void)
{
	char	*pnt1;
	int		i;

	pnt1 = ft_calloc(10, sizeof(char));
	i = 0;
	if (!pnt1)
		return (1);
	while (i < 10)
	{
		if (pnt1[i] != 0)
			return (1);
		i++;
	}
	free(pnt1);
	return (0);
}