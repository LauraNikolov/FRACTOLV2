/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:02:48 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/22 13:45:37 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	if (c == 0)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)str + i);
		i--;
	}
	if (c == 0 && str[i] == 0)
		return ((char *)str + i);
	return (NULL);
}
