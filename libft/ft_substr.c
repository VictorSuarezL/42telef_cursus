/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:50:36 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/09/25 12:01:41 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == 0)
		return (0);
	i = 0;
	subs[0] = '\0';
	if (start >= ft_strlen(s))
		return (subs);
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	if (len > (ft_strlen(s) - start))
		subs[ft_strlen(s) - start] = '\0';
	else
		subs[len] = '\0';
	return (subs);
}
