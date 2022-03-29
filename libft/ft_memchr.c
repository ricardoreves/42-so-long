/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:05:56 by rpinto-r          #+#    #+#             */
/*   Updated: 2021/10/19 22:47:45 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}

/* 
int main(){
	char s[] = "abcdef";
	printf("%s %s\n", ft_memchr(s, 'a', 0), NULL);
	printf("%s %s\n", ft_memchr(s, 'a', 1), s);
	printf("%s %s\n", ft_memchr(s, 'c', 3), s + 2);
	printf("%s %s\n", ft_memchr(s, 'g', 6), NULL);
}
*/