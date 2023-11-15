#include "shell.h"

/**
 * _strdup- copy a string
 * @str: string
 * Return: pointer to the string
 */

char *_strdup(char *str)
{
	int size, i;
	char *copy;

	size = 0;
	if (str == NULL)
		return (NULL);
	while (*(str + size))
		size++;
	size++; /* add 1 to print NULL*/
	copy = malloc((size) * sizeof(char));
	if (copy == NULL)
		return (0);
	for (i = 0; i < (size); i++)
		*(copy + i) = *(str + i);
	return (copy);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int j = 0, i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
	if (s1[i] != s2[i])
	{
	j = s1[i] - s2[i];
	return (j);
	}
	i++;
	}
return (j);
}

/**
* _strcpy - Copy paste string
* @dest: destination
* @src: source
* Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - a function that returns the length of a string
 * @s: string
 * Return: length of a string
 */

int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int lendest;
	int lensrc;
	int i;

	for (lendest = 0; dest[lendest] != '\0'; lendest++)
	{
	}
	for (lensrc = 0; src[lensrc] != '\0'; lensrc++)
	{
	}
	for (i = 0; i < lensrc; i++)
	{
	dest[i + lendest]  = src[i];
	}
return (dest);
}
