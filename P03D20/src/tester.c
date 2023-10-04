#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100
#define isDigit1(c) (c >= '0' && c <= '9')

typedef struct {
    char operators[MAX_EXPRESSION_LENGTH];
    double values[MAX_EXPRESSION_LENGTH];
    int top;
} Stack;

// int isdigit1(char symbol) {
//     int result = 0;
//     if (symbol >= 48 && symbol <= 57) result = 1;
//     return result;
// }

char *strreverse(char *origin) {
    int len = strlen(origin), i = 0;
    char* result[len];
    
    for(char *p = origin+len; origin > 0; origin--) {
        *result[i] = *p;
    }
    return *result;
}

void pushOperator(Stack* stack, char operator) {
    stack->operators[++(stack->top)] = operator;
}

void pushValue(Stack* stack, double value) {
    stack->values[++(stack->top)] = value;
}

char popOperator(Stack* stack) {
    return stack->operators[(stack->top)--];
}

double popValue(Stack* stack) {
    return stack->values[(stack->top)--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == 's' || c == 'c' || c == 't' || c == 'g' || c == 'q' || c == 'l');
}

int isUnaryOperator(char c) {
    return (c == 's' || c == 'c' || c == 't' || c == 'g' || c == 'q' || c == 'l');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == 's' || operator == 'c' || operator == 't' || operator == 'g' || operator == 'q' || operator == 'l')
        return 3;
    else
        return 0;
}

double calculateValue(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case 's':
            return sin(operand1);
        case 'c':
            return cos(operand1);
        case 't':
            return tan(operand1);
        case 'g':
            return 1 / tan(operand1);
        case 'q':
            return sqrt(operand1);
        case 'l':
            return log(operand1);
        default:
            return 0;
    }
}

double evaluateExpression(const char* expression) {
    Stack stack;
    stack.top = -1;

    int len = strlen(expression);
    for (int i = len - 1; i >= 0; i--) {
        char currentChar = expression[i];

        if (currentChar == ' ')
            continue;

        if (isdigit1(currentChar)) {
            char numberStr[MAX_EXPRESSION_LENGTH];
            int j = 0;
            while (i >= 0 && (isdigit1(expression[i]) || expression[i] == '.')) {
                numberStr[j++] = expression[i--];
            }
            numberStr[j] = '\0';
            double number = atof(strreverse(numberStr));
            pushValue(&stack, number);
        }
        else if (isOperator(currentChar)) {
            if (isUnaryOperator(currentChar)) {
                double operand = popValue(&stack);
                double result = calculateValue(operand, 0, currentChar);
                pushValue(&stack, result);
            }
            else {
                char operator = currentChar;
                double operand1 = popValue(&stack);
                double operand2 = popValue(&stack);
                double result = calculateValue(operand1, operand2, operator);
                pushValue(&stack, result);
            }
        }
    }

    return stack.values[stack.top];
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];

    printf("Введите выражение в обычной математической записи: ");
    fgets(expression, sizeof(expression), stdin);

    double result = evaluateExpression(expression);
    printf("Результат: %.2f\n", result);

    return 0;
}