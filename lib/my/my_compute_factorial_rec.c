/*
** EPITECH PROJECT, 2019
** factorial
** File description:
** factorial of parameter
*/

int my_compute_factorial(int factor)
{
    if (factor == 1)
        return (factor);
    factor *= my_compute_factorial(factor - 1);
    return (factor);
}