#include "shell.h"

/**
 * main - launches the shell
 * @ac: number of arguments
 * @av: array of arguments
 * @envs: array of environment variables
 *
 * Return: 0 for success, -1 for failure
 */
int main(__attribute__((unused))int ac,
        __attribute__((unused))char **av, char **envs)
{
        int status;
        char **arguments;
        char *line, *delim, *path_env, **path;

        envp = envs;
        arg = *av;
        delim = " \n";
        path_env = get_env("PATH");
        path = splitline(path_env, ":");
        do {
                _putchar('$');
                _putchar(' ');
                line = readline();
                /* condition to check if newline character is entered*/
                if (*line == '\n')
                        continue;
                arguments = splitline(line, delim);

                status = execute(arguments, envs);
                if (status == -1)
                        status = initialize_shell(arguments, path, envp);
        } while (status);
        return (status);
}
