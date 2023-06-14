/*
** EPITECH PROJECT, 2023
** compute.c
** File description:
** compute
*/
#include <stdlib.h>
#include <math.h>

double compute_polynome(int *poly, int size, double x)
{
    double result = ((double) poly[size]);

    for (int i = size - 1; i >= 0; i = i - 1)
        result = (result * x + ((double) poly[i]));
    free(poly);
    return (result);
}