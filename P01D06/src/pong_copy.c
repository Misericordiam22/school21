#include <stdio.h>

void cross_and_toe_display(int cross_pos, int toe_pos);
void draw_function(int x, int y, int ball_x, int ball_y, int rocket_left, int rocket_right, int rocket_left_x, int rocket_right_x);

int main() {

    // int cross_position, toe_position;
    // printf("Enter the \"X\" and \"O\" position:");

    // if (scanf("%d%d", &cross_position, &toe_position) != 2 || cross_position < 0 || toe_position < 0) {
    //     printf("Invalid position");
    //     return -1;
    // }

    // cross_and_toe_display(cross_position, toe_position);

    int ball_x = 40;
    int ball_y = 12;
    int ball_x_start = 40;
    int ball_y_start = 12;
    int rocket_left_y = 12;
    int rocket_right_y = 12;
    int rocket_left_x = 1;
    int rocket_right_x = 78;
    int x =  0;
    int y = 25;
    int direct_ball_x = 1;
    int direct_ball_y = 1;
    char symbol;

    while(1){ //сделать старт и остановку остановку @TODO
        
       // symbol = getchar();
        // usleep(40000);
        for(y = 25; y >= 0; y--){
             for(x = 0; x <= 79; x++){
                if (!(x = ball_x || y = ball_y) || y = 25 && y =0 && x = 79 && x = 0 && 
                (x = rocket_left_x && (y == rocket_left_y || y != rocket_left_y - 1 || y != rocket_left_y + 1)) &&
                (x != rocket_right_x || (y != rocket_right_y || y != rocket_right_y - 1 || y != rocket_right_y + 1)))
                printf(" ");
                
                // //  }
                // //  else{
                //      if(y == 25){
                //      printf("-");
                //  }
                if(y == 0 || y == 25){
                     printf("-");
                 }
                if(x == 0 && y >= 1 && y <= 24){
                     printf("|");
                 }
                if(x == 79 && y >= 1 && y <= 24){
                     printf("|");
                 }
                    
                if(x == ball_x && y == ball_y){
                     printf("o");
                 }
                if(x == rocket_left_x && (y == rocket_left_y || y == rocket_left_y - 1 || y == rocket_left_y + 1)){
                    printf("|");
                 }
                if(x == rocket_right_x && (y == rocket_right_y || y == rocket_right_y - 1 || y == rocket_right_y + 1)){
                    printf("|");
                 }
                 

             }
             printf("\n");
        }
        usleep(40000);

        //    
        // if (getchar() == ' ')
        //    draw_function( x,  y,  ball_x, ball_y,  rocket_left,  rocket_right,  rocket_left_x,  rocket_right_x);
           
    
        // }
       symbol = getchar();
        if (symbol  == 'k'){
            rocket_right_y++;
        }
        if (symbol  == 'm'){
            rocket_right_y--;
        }
        if (symbol  == 'a'){
            rocket_left_y++;
        }
        if (symbol == 'z'){
            rocket_left_y--;
        }
        
    
        if (ball_x == 78 || ball_x == 1){
                    direct_ball_x =  direct_ball_x * (-1);
        }
        if (ball_y == 24 || ball_y == 1){
                direct_ball_y =  direct_ball_y * (-1);
        }
            
        ball_x = ball_x + direct_ball_x;
        ball_y = ball_y + direct_ball_y;

        system("clear");
    }
    
}

void draw_function(int x, int y, int ball_x, int ball_y, int rocket_left, int rocket_right, int rocket_left_x, int rocket_right_x){

    for(y = 25; y >= 0; y--){
             for(x = 0; x <= 81; x++){
                 if(y == 25){
                     printf("-");
                 }
                if(y == 0){
                     printf("-");
                 }

                 if ((x != ball_x || y != ball_y) && y != 25 && y !=0 && x != 81 && x != 0)
                 printf(" ");
                  if(x == ball_x && y == ball_y){
                     printf("o");
                 }
                 if(x == rocket_left_x && (y == rocket_left || y == rocket_left - 1 || y == rocket_left + 1)){
                    printf("|");
                 }
                 if(x == rocket_right_x && (y == rocket_right || y == rocket_right - 1 || y == rocket_right + 1)){
                    printf("|");
                 }
                
                 
                // if (ball_x == 79 || ball_x == 1){
                //     direct_ball_x =  direct_ball_x * (-1);
                // }
                //    if (ball_y == 19 || ball_y == 1){
                //     direct_ball_y =  direct_ball_y * (-1);
                // }

             }
             printf("\n");
        }
}

void cross_and_toe_display(int cross_pos, int toe_pos) {
    char cross = 'X';
    char toe = 'o';
    char space = ' ';
    int max_pos = (cross_pos > toe_pos) ? cross_pos : toe_pos;
    for (int i = 0; i <= max_pos; i++) {
        if (i == cross_pos) {
            printf("%c", cross);
        } else if (i == toe_pos) {
            printf("%c", toe);
        } else {
            printf("%c", space);
        }
    }
}