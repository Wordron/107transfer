/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** separate_str
*/
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char **separate_str(char *argv, char *delim)
{
    int i = 0;
    char *temp;
    char **final = malloc(sizeof(char *) * 999);

    for (int j = 0; j != 999; j++)
        final[j] = malloc(sizeof(char) * 999);
    for (char *str = argv; ; str = NULL) {
        temp = strtok(str, delim);
        if (temp == NULL) {
            final[i] = NULL;
            return (final);
        }
        strcpy(final[i], temp);
        i++;
    }
}
