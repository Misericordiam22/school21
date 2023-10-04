#include "s21_string.h"

#include <stdio.h>
char *s21_strlen_test();
char *s21_strcmp_test();
char *s21_strcpy_test();

int main() {
#if LEN
    s21_strlen_test();
#endif
#if CMP
    s21_strcmp_test();
#endif
#if CPY
    s21_strcpy_test();
#endif
    return 0;
}

char *s21_strlen_test() {
    int n = 5;
    int counts[5] = {17, 20, 0, 2, 10};
    char *result;
    char *tests_data[5] = {"okey that is good", "hello 123 go walking", "", "//", "wonderFULL"};

    for (int i = 0; i < n; i++) {
        int temp = s21_strlen(tests_data[i]);
        if (temp != counts[i]) {
            result = "FAIL";
        } else {
            result = "SUCCESS";
        }
        printf("%s %d %s", tests_data[i], temp, result);
        if ((n - i - 1)) {
            printf("\n");
        }
    }

    return result;
}

char *s21_strcmp_test() {
    int n = 5;
    int counts[5] = {1, -1, 0, -1, 1};
    char *strings1[5] = {"abs", "123", "good", "Absolb", "success"};
    char *strings2[5] = {"abc", "124", "good", "absolat", "fail"};
    char *result;
    for (int i = 0; i < n; i++) {
        int temp = s21_strcmp(strings1[i], strings2[i]);
        if (temp < 0) temp = -1;
        if (temp > 0) temp = 1;
        if (temp != counts[i]) {
            result = "FAIL";
        } else {
            result = "SUCCESS";
        }
        printf("%s %s %d %s", strings1[i], strings2[i], temp, result);
        if ((n - i - 1)) {
            printf("\n");
        }
    }
    return result;
}

char *s21_strcpy_test() {
    int n = 5;
    // int counts[5] = {1, -1, 0, -1, 1};
    char *strings1[5];
    char *strings2[5] = {"abc", "124", "good", NULL, "fail"};
    char *result;
    // char *temp;
    for (int i = 0; i < n; i++) {
        s21_strcpy(strings1[i], strings2[i]);
        if (s21_strcmp(strings1, strings2)) {
        } else {
            result = "FAIL";
        }
        printf("%s %s %s %s", "", strings2[i], strings1[i], result);
        if ((n - i - 1)) {
            printf("\n");
        }
    }
    return result;
}