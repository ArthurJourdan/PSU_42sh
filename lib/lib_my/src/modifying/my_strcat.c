/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_strcat.c
*/

#include "my.h"
#include "print.h"

char *my_strcat_tot(size_t ac, ...)
{
    va_list ap;
    size_t len_tot = 0;
    char *str = NULL;
    char *one = NULL;

    va_start(ap, ac);
    for (size_t a = 0; a < ac; a++)
        len_tot = my_len_tot(va_arg(ap, char *));
    va_end(ap);
    str = malloc(sizeof(char) * (len_tot + 1));
    if (!(len_tot = 0) && !str)
        return NULL;
    va_start(ap, ac);
    for (size_t a = 0; a < ac; a++) {
        one = va_arg(ap, char *);
        for (size_t len_one = 0; len_one < my_strlen(one); len_one++)
            str[len_tot++] = one[len_one];
    } str[len_tot] = '\0';
    va_end(ap);
    return str;
}

static void free_cated_srings(char *str1, char *str2, bool free_1, bool free_2)
{
    if (free_1 && str1) {
        free(str1);
    }
    if (free_2 && str2) {
        free(str2);
    }
}

char *my_strcat(char *str1, char *str2, bool free_1, bool free_2)
{
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);
    size_t len3 = len1 + len2;
    char *str3 = NULL;

    if (!len3)
        return NULL;
    str3 = malloc(sizeof(char) * (len3 + 1));
    if (!str3)
        return NULL;
    for (size_t a = 0; a < len1; a++) {
        str3[a] = str1[a];
    }
    for (size_t b = 0; b < len2; b++) {
        str3[b + len1] = str2[b];
    }
    str3[len3] = '\0';
    free_cated_srings(str1, str2, free_1, free_2);
    return str3;
}