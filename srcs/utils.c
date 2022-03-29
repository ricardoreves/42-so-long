/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:29:22 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 04:25:56 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isfiletype(char *path, char *type)
{
	int	len;

	len = ft_strlen(path);
	return (ft_strncmp(path + len - ft_strlen(type), type, len) == 0);
}
