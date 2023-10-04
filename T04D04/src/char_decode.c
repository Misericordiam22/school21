#include <math.h>
#include <stdio.h>

int chartohex();
int hextochar();

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {
        printf("n/a");
        char d = *argv[1];
        if (d == '1') {
            hextochar();
        }
        if (d == '0') {
            chartohex();
        }
    }
}

int hextochar() {
    int i = 0;

    scanf("%x", &i);

    printf("%c\n", i);
    while (i != '\n') {
        scanf("%x", &i);

        printf("%c\n", i);
    }
    return (0);
}

int chartohex() {
    char ch;
    scanf("%c", &ch);

    printf("%x ", ch);

    while (ch != '\n') {
        scanf("%c", &ch);
        if (ch == ' ') continue;
        if (ch == '\n') return (0);
        printf("%x ", ch);
    }
    return (0);
}
