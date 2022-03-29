/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <rpinto-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:20:46 by rpinto-r          #+#    #+#             */
/*   Updated: 2021/10/18 14:06:53 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcpy() function copies up to size - 1 characters from the NUL-terminated
 string src to dst, NUL-terminating the result. 
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srcsize);
}

/* int main()
{
	char dest[10];
	
	printf("%lu\n", ft_strlcpy(dest, "hello", 10));
} */