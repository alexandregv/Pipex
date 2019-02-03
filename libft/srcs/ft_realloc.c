/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:11:34 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/23 18:32:14 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *s1, int lenght)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = ft_strnew(lenght + ft_strlen(s1))))
		return (NULL);
	ft_bzero(cpy, ft_strlen(s1) + lenght);
	ft_strncat(cpy, s1, ft_strlen(s1) + lenght);
	free(s1);
	s1 = NULL;
	return (cpy);
}
