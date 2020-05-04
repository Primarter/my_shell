/*
** EPITECH PROJECT, 2019
** task07
** File description:
** who is prime
*/

int my_is_prime2(int nb)
{
    for (int i = 2; i < nb; i += 1)
        if (nb % i == 0)
            return (1);
    return (0);
}

int my_find_prime_sup(int nb)
{
    while (my_is_prime2(nb) != 0)
        nb += 1;
    return (nb);
}