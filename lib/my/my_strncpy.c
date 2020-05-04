/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n characters from a string to another
*/

void my_strendcpy(char *dest, char const *src, int n)
{
    int idx = 0;

    for (int i = 0; dest && src && dest[idx] && src[i]; i++) {
        if (i >= n) {
            dest[idx] = src[i];
            idx++;
        }
    }
}

void my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; src && dest && src[i] && i < n; i++) {
        dest[i] = src[i];
    }
}