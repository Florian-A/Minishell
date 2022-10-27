/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_dequoting2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/10/03 21:44:52 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_expand_dequoting_a(void)
{
	char	*s1;
	char	*s2;
	int		is_dequoting;

	s1 = ft_strdup("$LANG\"OF\"");
	if (!s1)
		return (-1);
	s2 = expand_dequoting_string(s1, &is_dequoting);
	if (!s2)
		return (-1);
	if (ft_strcmp(s2, "en_US.UTF-8OF") != 0)
	{
		free(s1);
		free(s2);
		return (-1);
	}
	free(s1);
	free(s2);
	return (0);
}

int	test_expand_dequoting2(void)
{
	if (test_expand_dequoting_a() == -1)
		return (-1);
	return (0);
}
