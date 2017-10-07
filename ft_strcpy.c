/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:06:25 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:49:19 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*d;
	size_t	n;

	d = dst;
	n = (ft_strlen(src) + 1);
	while (n-- > 0)
	{
		if ((*dst++ = *src++) == '\0')
			break ;
	}
	return (d);
}
