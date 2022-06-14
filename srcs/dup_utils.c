#include "minishell.h"

void	dup_hub(t_cmd *cmd)
{
	if (cmd->redir_fd_out != STDOUT_FILENO)
	{
		if (dup2(cmd->redir_fd_out, STDOUT_FILENO) < 0)
			error(ER_DUP);
		close(cmd->redir_fd_out);
	}
	if (cmd->redir_fd_in != STDIN_FILENO)
	{
		if (dup2(cmd->redir_fd_in, STDIN_FILENO) < 0)
			error(ER_DUP);
		close(cmd->redir_fd_in);
	}
}

void	dup_back(int old_in, int old_out)
{
	if (old_out >= 0)
	{
		if (dup2(old_out, STDOUT_FILENO) < 0)
			error(ER_DUP);
		close(old_out);
	}
	if (old_in >= 0)
	{
		if (dup2(old_in, STDIN_FILENO) < 0)
			error(ER_DUP);
		close(old_in);
	}
    if (access("here_doc", F_OK) == 0 && unlink("here_doc"))
        error(ER_UNLINK);
}
