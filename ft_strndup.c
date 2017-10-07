/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:31:35 by agundry           #+#    #+#             */
/*   Updated: 2017/03/01 17:13:28 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;

	if ((result = (char *)ft_memalloc(n + 1)))
	{
		return (ft_strncpy(result, s1, n));
	}
	return (NULL);
}
