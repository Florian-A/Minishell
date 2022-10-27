/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by ███████           #+#    #+#             */
/*   Updated: 2022/10/11 14:40:55 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

void	test_block1(t_test *test)
{
	utest(test_input_parsing(), "input_parsing", test);
	utest(test_expand_parsed_input(), "expand_parsed_input", test);
	utest(test_expand_dequoting1(), "expand_dequoting1", test);
	utest(test_expand_dequoting2(), "expand_dequoting2", test);
}

int	main(int argc, char **argv, char **env)
{
	t_test	test;

	(void)argc;
	(void)argv;
	test.type = 1;
	g_minishell = ft_calloc(1, sizeof(t_minishell));
	g_minishell->env = env;
	arr_to_linked_list();
	test_init_struct(&test);
	test_show_start(&test);
	test_block1(&test);
	test_show_result(&test);
}
