/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes of all the lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdbool.h>

    int my_compute_factorial(int nb);
    int my_strlen(char const *str);
    int my_compute_power(int nb, int p);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_greatest(int a, int b);
    int my_lowest(int a, int b);
    void my_putchar(char c);
    int my_str_isnum(char const *str);
    void my_put_nbr(int n);
    void my_putstr(char const *str);
    char *my_revstr(char *str);
    int my_show_word_array(char * const *tab);
    void my_sort_int_array(int *tab, int size);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strncat(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_strncpy(char *dest, char const *src, int n);
    void my_strendcpy(char *dest, char const *src, int n);
    void my_swap(int *a, int *b);
    char *my_realloc_str(char *str, int size);
    int my_putnbr_base(long nbr, char const *base);
    int my_printf(char *str, ...);
    char *my_itos(long long nb);
    char **my_word_array(char *st);
    char **my_sep_array(char *st, char sep);
    char **my_append_array(char **array, char *str);
    char *my_append(char *str, char c);
    int str_not_empty(char const *str);
    size_t array_len(void *array);
    int num_test(char *str);
    void my_exit(char *str, int code);
    int alphanum_test(char *str);
    void free_array(void *array);
    bool return_msg(char const *msg, bool return_value, int const fd);
    ssize_t chompline(char **lineptr, size_t *n, FILE *stream);

    #ifndef FUNCTIONS_MY_PRINTF_H_
        #define FUNCTIONS_MY_PRINTF_H_

        #include <stdarg.h>
        #include <errno.h>
        #include <time.h>

        void my_flag_p(va_list ap);
        void my_flag_x(va_list ap);
        void my_flag_bigx(va_list ap);
        void my_flag_o(va_list ap);
        void my_flag_b(va_list ap);
        void my_flag_c(va_list ap);
        void my_flag_mod(va_list ap);
        void my_flag_m(va_list ap);
        void my_flag_bigs(va_list ap);
        void my_flag_u(va_list ap);
        void my_flag_d_i(va_list ap);
        void my_flag_s(va_list ap);

        typedef struct array_s {
            char c;
            void (*ptr)(va_list);
        } array_t;

    #endif /* FUNCTIONS_MY_PRINTF_H_ */
#endif /*MY_H_ */
