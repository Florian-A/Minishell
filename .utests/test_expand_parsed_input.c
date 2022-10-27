/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_parsed_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/10/05 11:50:08 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	expand_parsed_input1(void)
{
	char	*s1;

	s1 = analyze_expand_input("<< $NOENV >>");
	if (!s1)
		return (-1);
	if (ft_strcmp(s1, "<<  >>") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	expand_parsed_input2(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("E>$LANG<E");
	if (!s1)
		return (-1);
	s2 = analyze_expand_input(s1);
	if (!s2)
		return (-1);
	if (ft_strcmp(s2, "E>en_US.UTF-8<E") != 0)
	{
		free(s1);
		free(s2);
		return (-1);
	}
	free(s1);
	free(s2);
	return (0);
}

static int	expand_parsed_input3(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("TEST $LANG TEST");
	if (!s1)
		return (-1);
	s2 = analyze_expand_input(s1);
	free(s1);
	if (!s2)
		return (-1);
	if (ft_strcmp(s2, "TEST en_US.UTF-8 TEST") != 0)
	{
		free(s2);
		return (-1);
	}
	free(s2);
	return (0);
}

int	test_expand_parsed_input(void)
{
	if (expand_parsed_input1() == -1)
		return (-1);
	if (expand_parsed_input2() == -1)
		return (-1);
	if (expand_parsed_input3() == -1)
		return (-1);
	return (0);
}
