#include <stdio.h>km

void draw_field(int ball_x, int ball_y, int rocket_left_y, int rocket_right, int rocket_left_x,
                int rocket_right_x);
void draw_score(int player1_score, int player2_score);

void print_win(int player1_score);

char getch(void);

int main() {
    int ball_x = 39;
    int ball_y = 12, rocket_left_y = 12, rocket_right_y = 12;
    int rocket_left_x = 1, direct_ball_x = 1, direct_ball_y = 1;
    int rocket_right_x = 78;
    char symbol = 'n';
    int player1_score = 0, player2_score = 0;
    while ((symbol != 'q') && (player1_score < 21 && player2_score < 21)) {
        draw_field(ball_x, ball_y, rocket_left_y, rocket_right_y, rocket_left_x, rocket_right_x);
        draw_score(player1_score, player2_score);
        symbol = getchar();
        if (symbol == 'k' && rocket_right_y < 22)
            rocket_right_y++;
        else if (symbol == 'm' && rocket_right_y > 2)
            rocket_right_y--;
        else if (symbol == 'a' && rocket_left_y < 22)
            rocket_left_y++;
        else if (symbol == 'z' && rocket_left_y > 2)
            rocket_left_y--;
        else if (symbol != ' ')
            continue;
        // Удар об правую и левую ракетку
        if ((ball_x == 77 &&
             (ball_y == rocket_right_y || ball_y == rocket_right_y - 1 || ball_y == rocket_right_y + 1)) ||
            (ball_x == 2 &&
             (ball_y == rocket_left_y || ball_y == rocket_left_y - 1 || ball_y == rocket_left_y + 1))) {
            direct_ball_x = direct_ball_x * (-1);
        }
        // Удар об ракетку с угла
        if ((ball_x == 77 && (ball_y == rocket_right_y - 2 || ball_y == rocket_right_y + 2)) ||
            (ball_x == 2 && (ball_y == rocket_left_y - 2 || ball_y == rocket_left_y + 2))) {
            direct_ball_x = direct_ball_x * (-1);
            direct_ball_y = direct_ball_y * (-1);
        }
        if (ball_x == 78) {  // Удар об стену справа /Гол
            player1_score++;
            ball_x = 39;
            ball_y = 12;
        }
        if (ball_x == 1) {  // Удар об стену слева /Гол
            player2_score++;
            ball_x = 39;
            ball_y = 12;
        }
        if (ball_y == 23 || ball_y == 1) {  //Удар о нижнюю или верхнюю границу
            direct_ball_y = direct_ball_y * (-1);
        }
        ball_x = ball_x + direct_ball_x;
        ball_y = ball_y + direct_ball_y;
        system("clear");
    }
    if (symbol != 'q') print_win(player1_score);
}

void draw_field(int ball_x, int ball_y, int rocket_left_y, int rocket_right_y, int rocket_left_x,
                int rocket_right_x) {
    for (int y = 24; y >= 0; y--) {
        for (int x = 0; x <= 79; x++) {
            if (y == 24 || y == 0 || (x == 0 && y <= 23) || (x == 79 && y <= 23) ||
                (x == ball_x && y == ball_y) ||
                (x == rocket_left_x &&
                 (y == rocket_left_y || y == rocket_left_y - 1 || y == rocket_left_y + 1)) ||
                (x == rocket_right_x &&
                 (y == rocket_right_y || y == rocket_right_y - 1 || y == rocket_right_y + 1))) {
                if (y == 24 || y == 0) {
                    printf("-");
                }
                if ((x == 0 || x == 79) && y >= 1 && y <= 23) {
                    printf("|");
                }
                if (x == ball_x && y == ball_y) {
                    printf("o");
                }
                if (x == rocket_left_x &&
                        (y == rocket_left_y || y == rocket_left_y - 1 || y == rocket_left_y + 1) ||
                    x == rocket_right_x &&
                        (y == rocket_right_y || y == rocket_right_y - 1 || y == rocket_right_y + 1)) {
                    printf("|");
                }
            } else
                printf(" ");
        }
        printf("\n");
    }
}
//Отрисовываем счёт
void draw_score(int player1_score, int player2_score) {
    for (int y = 0; y <= 4; y++) {
        for (int x = 0; x <= 79; x++) {
            if (((y == 4 || y == 0) || ((x == 0 || x == 79 || x == 39 || x == 40))) ||
                (x >= 3 && x <= 12 && y == 2) || (x >= 42 && x <= 51 && y == 2) ||
                (x >= 3 && x <= 13 && y == 2 && (player1_score / 10 != 0)) ||
                (x >= 42 && x <= 52 && y == 2 && (player2_score / 10 != 0))) {
                if (y == 4 || y == 0) {
                    printf("-");
                }
                if ((x == 0 || x == 79 || x == 39 || x == 40) && y >= 1 && y < 4) {
                    printf("|");
                }
                if (x == 3 && y == 2) {
                    printf("PLAYER 1 %d", player1_score);
                }
                if (x == 42 && y == 2) {
                    printf("PLAYER 2 %d", player2_score);
                }
            } else
                printf(" ");
        }
        printf("\n");
    }
}
// Вывод победителя
void print_win(int player1_score) {
    if (player1_score == 21) {
        printf("Congratulations! Player1 WIN!!!");
    } else {
        printf("Congratulations! Player2 WIN!!!");
    }
}