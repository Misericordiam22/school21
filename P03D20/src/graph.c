#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 1000

// своя функция так как ctype нельзя
int isdigit1(char c) { return (int)(c >= '0' && c <= '9'); }

// не факт что это нужно!
// void strrev(char* str) {
//     if (str == NULL) return;

//     int len = strlen(str);
//     for (int i = 0; i < len / 2; ++i) {
//         char c = str[i];
//         str[i] = str[len - 1 - i];
//         str[len - 1 - i] = c;
//     }
// }

// Функция для проверки, является ли заданный символ оператором
int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 's' || c == 'c' || c == 't' ||
        c == 'l')
        return 1;
    return 0;
}

// Функция для проверки, является ли заданный символ числом
int is_operand(char c) {
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

// Функция для определения приоритета оператора
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Функция для обращения числа в польской нотации
void push_operand(char *stack, int *top, char operand) { stack[++(*top)] = operand; }

// Функция для обращения оператора в польской нотации
void push_operator(char *stack, int *top, char operator) {
    while (*top >= 0 && precedence(stack[*top]) >= precedence(operator)) {
        char temp = stack[(*top)--];
        printf("%c", temp);
    }
    stack[++(*top)] = operator;
}

// Функция для преобразования выражения в польскую нотацию
void infix_to_postfix(char *expression, char *result) {
    char stack[MAX_CAPACITY];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; expression[i]; i++) {
        if (expression[i] == ' ')
            continue;
        else if (is_operand(expression[i])) {
            result[j++] = expression[i];
            while (is_operand(expression[i + 1])) result[j++] = expression[++i];
            result[j++] = ' ';
        } else if (is_operator(expression[i])) {
            push_operator(stack, &top, expression[i]);
        } else if (expression[i] == '(') {
            stack[++top] = '(';
        } else if (expression[i] == ')') {
            while (stack[top] != '(') {
                result[j++] = stack[top--];
                result[j++] = ' ';
            }
            top--;
        }
    }

    while (top >= 0) {
        result[j++] = stack[top--];
        result[j++] = ' ';
    }

    result[j] = '\0';
}

// Функция для расчета значения выражения в польской нотации
double evaluate_postfix(char *expression) {
    int i;
    double stack[MAX_CAPACITY];
    int top = -1;

    for (i = 0; expression[i]; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            double num = 0;
            while (expression[i] != ' ') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            stack[++top] = num;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
                   expression[i] == '/' || expression[i] == '^') {
            double operand1 = stack[top--];
            double operand2 = stack[top--];
            double result;

            switch (expression[i]) {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
                case '^':
                    result = pow(operand2, operand1);
                    break;
            }
            stack[++top] = result;
        } else if (expression[i] == 's' || expression[i] == 'c' || expression[i] == 't' ||
                   expression[i] == 'l') {
            double operand1 = stack[top--];
            double result;

            switch (expression[i]) {
                case 's':
                    result = sin(operand1);
                    break;
                case 'c':
                    result = cos(operand1);
                    break;
                case 't':
                    result = tan(operand1);
                    break;
                case 'l':
                    result = log(operand1);
                    break;
            }
            stack[++top] = result;
        } else if (expression[i] == '-') {
            if (isdigit1(expression[i + 1])) {
                double num = 0;
                i++;
                while (expression[i] != ' ') {
                    num = num * 10 + (expression[i] - '0');
                    i++;
                }
                stack[++top] = -num;
            } else {
                double operand1 = stack[top--];
                double operand2 = stack[top--];
                stack[++top] = operand2 - operand1;
            }
        }
    }

    return stack[top];
}

// Функция для рисования графика функции
// здесь надо использовать нашу функцию
// void plot_graph(char *expression) {
//     int i, j;
//     double x, y;
//     printf("\n");

//     for(i = 24; i >= 0; i--) {
//         for(j = 0; j < 80; j++) {
//             if(i == 12 && j == 40) {
//                 printf("+");
//             }
//             else if(i == 12 && j != 40) {
//                 printf("-");
//             }
//             else if(j == 40 && i != 12) {
//                 printf("|");
//             }
//             else {
//                 x = ((double)j - 40) / 4;
//                 y = evaluate_postfix(expression, x); // тут отрисовка графика с готовой функцией вычисления
//                 //тут почему то область вобще 0.5 но так как у нас график сильно область гораздо меньше
//                 if(y >= ((double)i-0.5) && y <= ((double)i+0.5)) {
//                     printf("*");
//                 }
//                 else {
//                     printf(" ");
//                 }
//             }
//         }
//         printf("\n");
//     }
// }

void plot_graph(char *expression) {
    char point = '*', empty_field = '.';
    int length_field = 80, height_field = 25;
    for (int i = -12; i < height_field - 12; i++) {
        for (int j = 0; j < length_field; j++) {
            // double x = j / 5.0 * M_PI_2; // M_PI у меня не линкуется?! не робит
            // double x = j / 5.0 * 1.57; // если сверху отрабатывает это убрать
            double y = i / 11.0;
            // sin(x) = y
            // в if мы вызываем функцию которая возвращает значение и сравниваем c y

            double result_y =
                evaluate_postfix(expression);  // тут отрисовка графика с готовой функцией вычисления
            if (result_y - y < 0.08 && result_y - y > -0.08) {
                // if (sin(cos(2 * x)) - y < 0.08 && sin(cos(x)) - y > - 0.08) {
                printf("%c", point);
            } else {
                printf("%c", empty_field);
            }
        }
        printf("\n");
    }
}

int main() {
    char expression[MAX_CAPACITY], postfix_expression[MAX_CAPACITY];
    // double x_value;

    printf("Введите выражение: ");
    fgets(expression, MAX_CAPACITY, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    infix_to_postfix(expression, postfix_expression);

    // это не нужно ?!
    // printf("Польская нотация: %s\n", postfix_expression);

    // printf("Введите значение x: ");
    // scanf("%lf", &x_value);
    // getchar(); // Очистка буфера ввода

    // double result = evaluate_postfix(postfix_expression, x_value);
    // printf("Значение выражения при x = %.2lf: %.2lf\n", x_value, result);

    plot_graph(postfix_expression);

    return 0;
}
