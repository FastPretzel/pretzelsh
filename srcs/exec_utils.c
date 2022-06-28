#include "minishell.h"

int	check_pipes(char **token)
{
	int	i;
	int	pipe_cnt;

	i = -1;
	pipe_cnt = 0;
	while (token && token[++i])
	{
		if (ft_strcmp(token[i], "|", -1) == 0)
			pipe_cnt++;
	}
	return (pipe_cnt);
}

int	ft_arrlen(char	**arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

int	redir_num(char **token)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (token[++i])
	{
		if (ft_strcmp(token[i], ">", -1) == 0 ||\
				ft_strcmp(token[i], ">>", -1) == 0 ||\
				ft_strcmp(token[i], "<<", -1) == 0 ||\
				ft_strcmp(token[i], "<", -1) == 0)
			cnt++;
	}
	return (cnt);
}
