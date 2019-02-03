/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:30:57 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 15:47:41 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_istrlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

unsigned long	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	k;
	int		b;
	int		a;
	int		h;

	a = 0;
	b = 0;
	h = size;
	while (dest[a++] != '\0')
		h--;
	a--;
	k = ft_istrlen(dest);
	while (src[b] != '\0' && h > 1)
	{
		dest[a] = src[b];
		a++;
		b++;
		h--;
	}
	dest[a] = '\0';
	if (size < ft_istrlen(dest))
		return (size + ft_istrlen(src));
	return (k + ft_istrlen(src));
}
