/*
** EPITECH PROJECT, 2019
** power rec
** File description:
** power rec
*/

int my_compute_power(int nb, int p)
{
    if (p == 0)
        return (1);
    nb = nb * my_compute_power(nb, p - 1);
    return (nb);
}
