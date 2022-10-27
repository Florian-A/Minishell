/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_dequoting1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/10/03 21:45:02 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_expand_dequoting_a(void)
{
	char	*s1;
	int		is_dequoting;

	s1 = expand_dequoting_string("$LANG", &is_dequoting);
	if (!s1)
		return (-1);
	if (ft_strcmp(s1, "en_US.UTF-8") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	test_expand_dequoting_b(void)
{
	char	*s1;
	char	*s2;
	int		is_dequoting;

	s1 = ft_strdup("\"-E$LANG US\" '$LANG $US'#\" \"#'# #'#\"\"#''#");
	if (!s1)
		return (-1);
	s2 = expand_dequoting_string(s1, &is_dequoting);
	free(s1);
	if (!s2)
		return (-1);
	if (ft_strcmp(s2, "-Een_US.UTF-8 US $LANG $US# ## ####") != 0)
	{
		free(s2);
		return (-1);
	}
	free(s2);
	return (0);
}

static int	test_expand_dequoting_c(void)
{
	char	*s1;
	int		is_dequoting;

	s1 = expand_dequoting_string("'-NE$LANG'\"-E$LANG\"''-E\
	$LANG''\"''\"-E$LANG\"''\"", &is_dequoting);
	if (!s1)
		return (-1);
	if (ft_strcmp(s1, "-NE$LANG-Een_US.UTF-8-E\
	en_US.UTF-8''-Een_US.UTF-8''") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	test_expand_dequoting_d(void)
{
	char	*s1;
	int		is_dequoting;

	s1 = expand_dequoting_string("\"1 2\"3'4 5'6\"7 8\"9", &is_dequoting);
	if (!s1)
		return (-1);
	if (ft_strcmp(s1, "1 234 567 89") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

int	test_expand_dequoting1(void)
{
	if (test_expand_dequoting_a() == -1)
		return (-1);
	if (test_expand_dequoting_b() == -1)
		return (-1);
	if (test_expand_dequoting_c() == -1)
		return (-1);
	if (test_expand_dequoting_d() == -1)
		return (-1);
	return (0);
}
