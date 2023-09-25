/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:45:36 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/09/25 18:21:27 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
	int i;
	int j;
	char **array;
	int start;
	int end;
	int array_num;

	j = 0;
	i = 0;
	if (s == 0)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			j++;
		}
		i++;
	}
	if(i == j)
	{
		return(0);
	}
	if (s[0] == c)
	{
		j--;
	}
	if (s[ft_strlen(s)-1] == c)
	{
		j--;
	}
	array = (char **)malloc(sizeof(char *) * (j + 1));
	if(array == 0)
		return 0;
	i = 0;
	start = 0;
	end = 0;
	array_num = 0;
	while (s[i])
	{
		if (s[i] == c && s[i+1] != c)
		{
			end = i;
			array[array_num] = ft_substr(s, start, end - start);
			i++;
			start = i;
			array_num++;
		}
		if (array_num == j)
		{
			if (s[ft_strlen(s)-1] == c)
			{
				array[array_num] = ft_substr(s, start, ft_strlen(s) - start - 1);
			}
			else
				array[array_num] = ft_substr(s, start, ft_strlen(s) - start);
			return (array);
		}
		i++;
	}
	return(0);
}
