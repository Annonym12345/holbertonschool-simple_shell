#include "shell.h"

/**
 * launch - Launch an external program
 * @args: Array of arguments (NULL terminated)
 *
 * Return: 1 to continue execution
 */
int launch(char **args)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = get_path(args[0]);
	if (cmd == NULL)
	{
		perror(args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror(args[0]);
			if (cmd != args[0])
				free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
	}

	if (cmd != args[0])
		free(cmd);

	return (1);
}
