/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:08:56 by ladrian           #+#    #+#             */
/*   Updated: 2022/07/03 17:21:42 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_start_of_envp(int *j, int k, char *str)
{
	int	a;

	a = -1;
	*j = a;
	k = find_dollar(str);
	return (k);
}
