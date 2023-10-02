/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:21:44 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/10/02 16:26:52 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/vsanz-su/Documents/cursus/libft/libft.h"
#include <stdio.h>

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*byte_b;
// 	unsigned char	byte_value;
// 	size_t			i;

// 	byte_b = (unsigned char *)b;
// 	byte_value = (unsigned char)c;
// 	i = 0;
// 	while (i < len)
// 	{
// 		byte_b[i] = byte_value;
// 		i++;
// 	}
// 	return (b);
// }

int num_len(int n)
{
	int is_negative;
	int i;

	is_negative = 0;
	i = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return(is_negative + i);
}

char *ft_itoa(int n)
{
	int i;
	unsigned int aux;
	char *p;
	int len;
	char temp;

	aux = n;
	len = num_len(n);
	i = len;
	temp = 0;

	// printf("n = %i ", n);
	// printf("y tiene %i cifras\n", num_len(n));

	p = (char *)malloc((len + 1) * sizeof(char));
	if(p == 0)
		return(0);
	p[len] = '\0';
	while (aux > 0)
	{
		temp = (aux % 10) + 48;
		// printf("pos = %i value = %c\n", len, temp);
		p[len] = temp;
		aux = aux/10;
	}
	p[len + 1] = 0;

	return(p);
}

int main(void)
{
	// ft_itoa(1000);
	// ft_itoa(-1000);
	printf("El número es: %s\n", ft_itoa(1234));

	return(0);
}
