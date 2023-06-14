/*
** EPITECH PROJECT, 2023
** calculate.c
** File description:
** calculate
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/107_transfer.h"

static int get_total_nb(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '*')
            nb++;
    }
    return (nb);
}

static int *convert_to_int(char **array)
{
    int size = 0;
    while (array[size] != NULL)
        size++;
    int *int_arr = malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++)
        int_arr[i] = atoi(array[i]);
    return (int_arr);
}

static void free_arr(char **arr)
{
    for (int i = 0; i < 999; i++)
        free(arr[i]);
    free(arr);
}

int calcul(int ac, char **av)
{
    double result = 1;
    double denum_result = 0;
    char *temp_denum = NULL;
    char *temp_num = NULL;
    char **num = NULL;
    char **denum = NULL;

    for (double x = 0; x <= 1.001; x = x + 0.001) {
        result = 1;
        for (int j = 1; j + 1 < ac; j = j + 2) {
            temp_num = strdup(av[j]);
            temp_denum = strdup(av[j + 1]);
            num = separate_str(temp_num, "*");
            denum = separate_str(temp_denum, "*");
            free(temp_num);
            free(temp_denum);
            denum_result = compute_polynome(convert_to_int(denum), get_total_nb(av[j + 1]), x);
            if (denum_result < 0.0001 && denum_result > -0.0001)
                exit(84);
            result = (result * compute_polynome(convert_to_int(num), get_total_nb(av[j]), x) / denum_result);
            free_arr(num);
            free_arr(denum);
        }
        printf("%.3f -> %.5f\n", x, result);
    }
    exit(0);
}
