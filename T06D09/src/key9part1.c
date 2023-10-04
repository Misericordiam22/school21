/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void sum_numbers(int *buffer, int length, int *sum);
void getCountEven(int *a, int n, int *count);
void getCountDiviser(int *a, int n, int sum, int *count_diviser);
void output(int *buffer, int length, int sum);
void find_numbers(int *buffer, int length, int sum, int *numbers);

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
    int n, sum, count_even, count_diviser, a[NMAX];
    if (input(a, &n) != 0) {
        getCountEven(a, n, &count_even);
        if (count_even == 0) {
            printf("n/a");
            return 0;
        }
        sum_numbers(a, n, &sum);
        getCountDiviser(a, n, sum, &count_diviser);
        int result_numbers[count_diviser];
        find_numbers(a, n, sum, result_numbers);
        output(result_numbers, count_diviser, sum);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length < 1 || *length > 10) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        };
    }
    return 1;
}

void output(int *buffer, int count, int sum) {
    printf("%d\n", sum);
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
void sum_numbers(int *buffer, int length, int *sum) {
    *sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i] != 0) {
            *sum += buffer[i];
        }
    }
}

// кол-во чётных, кроме 0
void getCountEven(int *buffer, int length, int *count) {
    int count1 = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && *p % 2 == 0) {
            count1++;
        }
    }
    *count = count1;
}

//Кол-во делителей для создания массива этих чисел
void getCountDiviser(int *buffer, int length, int sum, int *count_diviser) {
    int i = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if ((*p != 0) && (sum % *p == 0)) {
            i++;
        }
    }
    *count_diviser = i;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
void find_numbers(int *buffer, int length, int sum, int *numbers) {
    int i = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if ((*p != 0) && (sum % *p == 0)) {
            numbers[i] = *p;
            i++;
        }
    }
}
