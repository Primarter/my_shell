/*
** EPITECH PROJECT, 2019
** square root
** File description:
** my square root
*/

int my_compute_square_root(int nb)
{
    int sqrt = 2;

    if (nb <= 2)
        return (-1);
    while (sqrt * sqrt != nb && sqrt < nb)
        sqrt += 1;
    if (sqrt == nb)
        return (-1);
    else
        return (sqrt);
}
