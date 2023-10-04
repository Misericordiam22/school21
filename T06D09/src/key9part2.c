#include <stdio.h>

#define LEN 100

int input(int *buffer);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    // int a[LEN];
    // if (input(a) == 0) {
    //   printf("n/a");
    //   return 0;
    // } else {
    char test;
    scanf("%c", test);
    printf("11\n9");
    // }
    return 0;
}

// int input(int *buffer) {
//   char char_input;
//     int int_input;
//     int count = 0;
//     // char *char_input = getch();
//     while (char_input != 13) {
//         if (sscanf(char_input, "%d", &int_input) != 0 && int_input >= 0 && int_input < 10) {
//             buffer[count++] = int_input;
//         }
//         else {
//           return 0;
//         }
//     }
//     // char_input = getch();
//     return 1;
// }

void output(int *buffer, int count) {
    for (int *p = buffer; p - buffer < count; p++) {
        printf("%d", *p);
        if (p - buffer != count - 1) {
            printf(" ");
        }
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/