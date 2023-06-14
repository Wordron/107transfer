/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <stdlib.h>
#include "include/107_transfer.h"

static int my_str_is_float(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '.' || str[i] == '*' || str[i] == '-')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3 || ac % 2 == 0)
        return (84);
    for (int i = 1; i < ac; i++) {
        if (my_str_is_float(av[i]) == 0)
            return (84);
    }
    calcul(ac, av);
}
