/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr2dlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by ███████           #+#    #+#             */
/*   Updated: 2022/09/07 18:19:39 by ███████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_arr2dlen(void **arr)
{
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
		i++;
	return (i);
}
