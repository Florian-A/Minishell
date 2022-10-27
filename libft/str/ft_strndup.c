/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by ███████           #+#    #+#             */
/*   Updated: 2022/05/10 11:07:48 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s1, int j)
{
	char	*pnt;
	int		i;

	pnt = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (s1[i] && i < j)
	{
		pnt[i] = s1[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
