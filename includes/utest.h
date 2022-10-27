/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by ███████           #+#    #+#             */
/*   Updated: 2022/10/09 13:52:36 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTEST_H
# define UTEST_H

# include "../libft/includes/libtest.h"
# include "./minishell.h"

int	test_input_parsing(void);
int	test_expand_parsed_input(void);
int	test_expand_dequoting1(void);
int	test_expand_dequoting2(void);

#endif