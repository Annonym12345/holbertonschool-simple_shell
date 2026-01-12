#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/**
 * struct builtin - Builtin struct for command name and function
 * @name: The name of the builtin command
 * @func: The function pointer
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **args);
} builtin_t;

extern char **environ;
extern int last_status;

/* Main functions - Task 1 */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int launch(char **args);

/* Path function - Task 2 */
char *get_path(char *cmd);
char *check_direct_path(char *cmd);
char *build_full_path(char *dir, char *cmd);
char *search_in_path(char *cmd, char *path);

/* Builtin functions - Tasks 3, 4, 5 */
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_setenv(char **args);
int builtin_unsetenv(char **args);

/* Environment functions - Task 5 */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int compare_env_name(char *env_str, const char *name, size_t len);

/* Helper functions */
void free_array(char **array);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);

#endif
