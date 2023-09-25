/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:00:48 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/09/21 16:47:33 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;

	if (count <= 0 || size <= 0)
	{
		buffer = (char *)malloc(1);
	}
	else
	{
		buffer = (char *)malloc(count * size);
	}
	if (!buffer)
	{
		return (NULL);
	}
	return (ft_memset(buffer, 0, count * size));
}
