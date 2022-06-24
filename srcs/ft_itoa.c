/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:49:00 by cgoth             #+#    #+#             */
/*   Updated: 2022/06/24 16:15:09 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	recurs(int n, char *str, int size)
{
	if (n / 10 != 0 && size > 0)
	{
		size--;
		recurs(n / 10, str, size);
		size++;
	}
	str[size] = (n % 10) + '0';
}

static void	recurs_otr(unsigned int n, char *str, int size)
{
	if (n / 10 != 0 && size > 1)
	{
		size--;
		recurs(n / 10, str, size);
		size++;
	}
	str[size] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*str;

	i = 1;
	nb = n;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	if (n < 0)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		/*return (NULL);*/
		error_exit(ER_MALLOC);
	if (n < 0)
	{
		recurs_otr((unsigned int)(n * (-1)), str, i - 1);
		str[0] = '-';
	}
	else
		recurs(n, str, i - 1);
	str[i] = '\0';
	return (str);
}
