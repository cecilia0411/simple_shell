#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

/* Execute Functions */

char *get_path(char *name);
int check_slash(const char *str);
char *path_cmd(char *path, char *cmd);
char *tokenize(char *str, char *line);
char *cc_readline(void);
void execute_cmd(char *input, char *argv[], char **env);
void display_prompt(void);
char *handle_hashtag(char *name);

/* Built in Functions */

int handle_builtin(char **args);
int change_dir(char **cmd);
void print_env(char **env);
int cc_exit(char **ar, char *str);
void h_exit(char *index, int status);
int cc_unsetenv(char **args);
int cc_setenv(char **args);

/* Helper Functions */

char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
void *malloc_checked(unsigned int b);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strchr(char *s, char c);
int is_delim(char c, char *delim);
int _isalpha(int c);

/* Buffers */
#define PATH_MAX 4096
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#endif /* SHELL_H */
