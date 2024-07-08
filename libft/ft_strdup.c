/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:05:20 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 14:05:53 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*src;
	size_t	len;
	char	*cpy;
	size_t	i;

	if (!source)
		return (NULL);
	src = (char *)source;
	len = ft_strlen(src) + 1;
	cpy = malloc(len);
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
