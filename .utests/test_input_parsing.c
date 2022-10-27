/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/10/05 15:50:03 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_input_parsing1(void)
{
	t_list	*lst_parsed_input;

	lst_parsed_input = input_parsing("test");
	if (ft_strcmp(lst_parsed_input->content, "test") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	lst_parsed_input = input_parsing("ls -la /");
	if (ft_strcmp(lst_parsed_input->content, "ls") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "-la") != 0
		|| ft_strcmp(lst_parsed_input->next->next->content, "/") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	lst_parsed_input = input_parsing("echo \"this is a litle\" test");
	if (ft_strcmp(lst_parsed_input->content, "echo") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "\"this is a litle\"") != 0
		|| ft_strcmp(lst_parsed_input->next->next->content, "test") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	return (0);
}

static int	test_input_parsing2(void)
{
	t_list	*lst_parsed_input;

	lst_parsed_input = input_parsing("echo 'this is a litle' test");
	if (ft_strcmp(lst_parsed_input->content, "echo") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "'this is a litle'") != 0
		|| ft_strcmp(lst_parsed_input->next->next->content, "test") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	lst_parsed_input = input_parsing("echo \"'is a test'\" test");
	if (ft_strcmp(lst_parsed_input->content, "echo") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "\"'is a test'\"") != 0
		|| ft_strcmp(lst_parsed_input->next->next->content, "test") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	lst_parsed_input = input_parsing("echo '\"is a test\"' test");
	if (ft_strcmp(lst_parsed_input->content, "echo") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "'\"is a test\"'") != 0
		|| ft_strcmp(lst_parsed_input->next->next->content, "test") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	return (0);
}

static int	test_input_parsing3(void)
{
	t_list	*lst_parsed_input;

	lst_parsed_input = input_parsing("\"bin/cat\" 'Makefile'");
	if (ft_strcmp(lst_parsed_input->content, "\"bin/cat\"") != 0
		|| ft_strcmp(lst_parsed_input->next->content, "'Makefile'") != 0)
		return (-1);
	ft_lstclear(&lst_parsed_input, &free);
	return (0);
}

int	test_input_parsing(void)
{
	if (test_input_parsing1() == -1)
		return (-1);
	if (test_input_parsing2() == -1)
		return (-1);
	if (test_input_parsing3() == -1)
		return (-1);
	return (0);
}
