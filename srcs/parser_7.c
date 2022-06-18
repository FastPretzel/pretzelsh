/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:32:24 by ladrian           #+#    #+#             */
/*   Updated: 2022/06/18 17:53:11 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", sizeof(char));
}

void	parse_error(int error)
{
	if (error == QUOTE_ERR)
		ft_putendl_fd("error: unclosed qoutes", STDERR_FILENO);
	else if (error == PIPE_ERR)
		ft_putendl_fd("error: bad pipes", STDERR_FILENO);
}

int	find_reverse_pipe(char *token)
{
	int	i;

	i = -1;
	while (token[++i])
		;
	while (--i > -1)
	{
		if (ft_isalpha(token[i]) || ft_isdigit(token[i]))
			break ;
		else if (token[i] == '|')
			return (1);
	}
	return (0);
}