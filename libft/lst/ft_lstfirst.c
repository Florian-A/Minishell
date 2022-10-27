/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by ███████           #+#    #+#             */
/*   Updated: 2022/05/10 11:07:26 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	int		i;
	t_list	*lst1;

	if (lst != NULL)
	{
		i = 1;
		lst1 = lst;
		while (lst1->previous != NULL)
		{
			lst1 = lst1->previous;
			i++;
		}
		return (lst1);
	}
	else
		return (0);
}
