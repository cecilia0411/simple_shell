#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory
 * @b: constant
 * @n: memory bytes
 * Return: the pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] =  b;

	return (s);
}

/**
 * _memcpy - fills memory with another buffer.
 * @dest: source string
 * @src: string for filling
 * @n: nunber of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
* _atoi - changes a string to an int
* @s: the string to be changed
*
* Return: the converted int
*/

int _atoi(char *s)
{
	int i = 1;
	unsigned int num = 0;

	do {
	if (*s == '-')
	i *= -1;
	else if (*s >= '0' && *s <= '9')
	num = num * 10 + (*s - '0');
	else if (num > 0)
	break;
	} while (*s++);
	return (num * i);
}

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory
 * Return: the string
 */

void *malloc_checked(unsigned int b)
{
	void *meloc;

	meloc = malloc(b);
	if (meloc == NULL)
		exit(98);
	return (meloc);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character
 *Return: a pointer to the memory
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
