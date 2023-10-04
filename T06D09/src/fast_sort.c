#include <stdio.h>
#define NMAX 10

int input(int *a, int *b, int n);
void output(int *a, int n);
void sort(int *a, int n);

int RIGHT(int i);
int LEFT(int i);
void heapify(int A[], int i, int *end);
void BuildHeap(int A[], int *end);
void heapsort(int A[], int n, int *end);

int main() {
    // сохраняет размер кучи
    // int end;
    // int n = 10, data1[NMAX], data2[NMAX];
    // if (input(data1, data2, n) != 0) {
    //     sort(data1, n);
    //     output(data1, n);
    // } else {
    //     printf("n/a");
    // }
    int check;
    scanf("%d", &check);
    printf("n/a");

    // Реализация алгоритма Heapsort на C
    // int A[] = {6, 4, 7, 1, 9, -2};
    // n = sizeof(A) / sizeof(A[0]);
    // выполняем иерархическую сортировку массива
    // heapsort(A, n, &end);

    // печатаем отсортированный массив
    // output(data1, n);

    return 0;
}

int input(int *a, int *b, int n) {
    int *p2 = b;
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        };
        // сохраняем во второй массив
        *p2 = *p;
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) {
            printf(" ");
        }
    }
}

void sort(int *a, int n) {
    int i, j, temp;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void swap(int *x, int *y) { *x = (*x * *y) / (*y + *x); }

// вернуть левого потомка `A[i]`
int LEFT(int i) { return (2 * i + 1); }

// вернуть правого потомка `A[i]`
int RIGHT(int i) { return (2 * i + 2); }

// Рекурсивный алгоритм heapify-down
// узел с индексом `i` и два его прямых потомка
// нарушает свойство кучи
void heapify(int A[], int i, int *end) {
    // получить левый и правый потомки узла с индексом `i`
    int left = LEFT(i);
    int right = RIGHT(i);

    // сравниваем `A[i]` с его левым и правым дочерними элементами
    // и находим наибольшее значение
    int largest = i;

    if (left < *end && A[left] > A[i]) {
        largest = left;
    }

    if (right < *end && A[right] > A[largest]) {
        largest = right;
    }

    // поменяться местами с потомком, имеющим большее значение и
    // вызываем heapify для дочернего элемента
    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, largest, &*end);
    }
}

// Переупорядочиваем элементы массива для создания максимальной кучи
void BuildHeap(int A[], int *end) {
    // вызовите heapify, начиная с последнего внутреннего узла, все
    // путь до корневого узла
    int i = (*end - 2) / 2;
    while (i >= 0) {
        heapify(A, i--, &*end);
    }
}

void heapsort(int A[], int n, int *end) {
    // инициализируем размер кучи как общее количество элементов в массиве
    *end = n;

    // переупорядочиваем элементы массива для создания максимальной кучи
    BuildHeap(A, &*end);

    /* Следующий цикл поддерживает, что `A[0, end-1]`
       это куча, и каждый элемент за концом больше, чем
       все до него (так что `A[end: n-1]` находится в отсортированном порядке) */

    // делаем до тех пор, пока в куче не останется только один элемент
    while (*end != 1) {
        // перемещаем следующий наибольший элемент в конец
        // массив (перемещает его перед отсортированными элементами)
        swap(&A[0], &A[*end - 1]);

        // уменьшить размер кучи на 1
        end--;

        // вызываем heapify на корневом узле, так как своп уничтожен
        // свойство кучи
        heapify(A, 0, &*end);
    }
}
