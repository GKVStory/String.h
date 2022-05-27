#include "s21_string.h"

unsigned long long int s21_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte) {
    unsigned long long res = 0;
    short sign = 1;
    char dict[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (*string == '-') {
        sign = -1;
        string++;
    }
    long long val;
    short exit = 0;
    while (*string && n_byte && !exit) {
        char *tmp2;
        char current_sim =
                (*string >= 'a' && *string <= 'z') ? *string - 'a' + 'A' : *string;
        tmp2 = s21_strchr(dict, (int) current_sim);
        val = (tmp2 - dict) / sizeof(char);
        res = res * basis + val;
        string++;
        n_byte--;

    }
    return res * sign;
}
