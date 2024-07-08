/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:47:15 by lnicolof          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:24 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0 && str[i] == 0)
		return ((char *)str + i);
	return (NULL);
}
/*int	main(void)
{
	char s[] = "tripouille";
	printf("%s\n", ft_strchr(s, 'l'));
	printf("%s", strchr(s, 'l'));
}*/