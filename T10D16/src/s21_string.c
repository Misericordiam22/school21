#include "s21_string.h"

#include <stdio.h>

unsigned long s21_strlen(const char* chars) {
    unsigned int strlength = 0;
    for (; *(chars + strlength); strlength++)
        ;
    return strlength;
}

long s21_strcmp(const char* chars1, const char* chars2) {
    for (; *chars1 && *chars1 == *chars2; chars1++, chars2++)
        ;
    return *chars1 - *chars2;
}

char* s21_strcpy(char* chars1, const char* chars2) {
    int i = 0;
    for (; *(chars2 + i); i++) {
        chars1[i] = chars2[i];
    }
    chars1[i] = '\0';
    return chars1;
}