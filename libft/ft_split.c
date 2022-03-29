/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <rpinto-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:53:04 by rpinto-r          #+#    #+#             */
/*   Updated: 2021/10/22 14:02:46 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	compute_tab_size(char *s, char c)
{
	int	i;

	i = 0;
	if (!c)
		return (1);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			return (0);
		while (*s != c && *s != 0)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

static	int	malloc_tab_entry(char **tab, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	if (!c)
		return (1);
	while (*s)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s != 0)
		{
			j++;
			s++;
		}
		tab[i] = malloc(sizeof(char) * (j + 1));
		if (!tab[i])
			return (0);
		while (*s == c)
			s++;
		i++;
	}
	return (1);
}

static	char	**copy_tab_entry(char **tab, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	if (!c)
	{
		tab[0] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!tab[0])
			return (0);
		ft_strlcpy(tab[0], s, (ft_strlen(s) + 1));
	}
	while (c && *s)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s != 0)
			tab[i][j++] = *s++;
		tab[i][j] = 0;
		while (*s == c)
			s++;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_size;

	tab_size = compute_tab_size((char *)s, c);
	tab = malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (0);
	else if (!tab_size || !*s)
		tab[0] = 0;
	else if (malloc_tab_entry(tab, (char *)s, c))
		copy_tab_entry(tab, (char *)s, c);
	else
	{
		free(tab);
		return (0);
	}
	tab[tab_size] = 0;
	return (tab);
}

/* 
int main()
{
  	char **tab;
	tab = ft_split("lorem ipsum dolor sit amet,  elit. Sed s. Suspendisse0", ' ');

	(void)tab;
	//printf("%s %s\n", tab[0], tab[1]);

	tab = ft_split("   lorem   ipsum dolor     sit amet, cSed nodisse1   ", ' ');
	//(void)tab;

	//printf("out: %s\n", tab[0]);

	tab = ft_split("lorem entum ultricies diam. Maecenas liongue, non, mi.", 'i');
	//(void)tab;

	tab = ft_split(" ultricies diam. Maecen, varius a, semper cnon, mi.", 0);
	//(void)tab;
	//printf("out: %s\n", tab[0]);

	//tab = ft_split("zzzzzzz", 'z');
	///(void)tab;
	//printf("out: %s\n", tab[0]);
 
	//printf("tab_size: %d\n", compute_tab_size("hello ricardo", ' '));
	//printf("tab_size: %d\n", compute_tab_size("    hello ricardo", ' '));
	//printf("tab_size: %d\n", compute_tab_size("hello ricardo     ", ' '));
	//printf("tab_size: %d\n", compute_tab_size("hello     ricardo", ' '));
	//printf("tab_size: %d\n", compute_tab_size("    hello ricardo  ", ' '));
	//printf("tab_size: %d\n", compute_tab_size("  a", ' '));
	//printf("tab_size: %d\n", compute_tab_size("a", ' '));
	//printf("tab_size: %d\n", compute_tab_size("a ", ' '));
	//printf("tab_size: %d\n", compute_tab_size(" a", ' '));
	//printf("tab_size: %d\n", compute_tab_size("    ", ' '));
	//printf("tab_size: %d\n", compute_tab_size(" ", ' '));
	//printf("tab_size: %d\n", compute_tab_size("", ' '));
	printf("tab_size: %d\n", compute_tab_size("ooooo", 0));
	printf("tab_size: %d\n", compute_tab_size("ooooo", 'd'));
	printf("tab_size: %d\n", compute_tab_size("      ", ' ')); // 0
	printf("tab_size: %d\n", compute_tab_size("", ' ')); //0

}
   */