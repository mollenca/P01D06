#include <math.h>
#include <stdio.h>

int move_racket_1(char a) {
    switch (a) {
        case 'a':
            return -1;
            break;
        case 'z':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
int move_racket_2(char a) {
    switch (a) {
        case 'k':
            return -1;
            break;
        case 'm':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

void display(int racket1_y, int racket2_y, int ball_x, int ball_y, int score1, int score2) {
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 80; j++) {
            switch (i) {
                case 0:
                    printf("-");
                    break;
                case 1:
                    switch (j) {
                        case 0:
                            printf("|");
                            break;
                        case 37:
                            printf("%-2d", score1);
                            j++;
                            break;
                        case 40:
                            printf("|");
                            break;
                        case 42:
                            printf("%2d", score2);
                            j++;
                            break;
                        default:
                            printf(" ");
                            break;
                        case 79:
                            printf("|");
                            break;
                    }
                    break;
                case 2:
                    printf("-");
                    break;
                case 3 ... 28:
                    if (((racket1_y == i || racket1_y == i - 1 || racket1_y == i + 1) && (j == 20)) ||
                        ((racket2_y == i || racket2_y == i - 1 || racket2_y == i + 1) && (j == 60))) {
                        printf("|");
                    } else {
                        if (j == ball_x && i == ball_y) {
                            printf("*");
                        } else {
                            if (j == 40) {
                                printf("|");
                            } else {
                                printf(" ");
                            }
                        }
                    }

                    break;
            }
        }
        printf("\n");
    }
}
int change_vector_ball_x(int vector_ball_x, int ball_x, int ball_y, int racket1_y, int racket2_y) {
    if ((ball_x == 21 && (ball_y == racket1_y || racket1_y++ == ball_y || racket1_y-- == ball_y)) ||
        (ball_x == 59 && (ball_y == racket2_y || racket2_y++ == ball_y || racket2_y-- == ball_y))) {
        vector_ball_x = -vector_ball_x;
    }
    return vector_ball_x;
}
int change_vector_ball_y(int vector_ball_y, int ball_y) {
    if ((ball_y == 3) || (ball_y == 28)) {
        vector_ball_y = -vector_ball_y;
    }
    return vector_ball_y;
}
int move_ball_y(int vector_ball_y, int ball_y) {
    switch (vector_ball_y) {
        case 1:
            ball_y++;
            break;
        case -1:
            ball_y--;
            break;
    }
    return ball_y;
}
int move_ball_x(int vector_ball_x, int ball_x) {
    switch (vector_ball_x) {
        case 1:
            ball_x++;
            break;
        case -1:
            ball_x--;
            break;
    }
    return ball_x;
}

int main() {
    int racket1_y = 16;
    int racket2_y = 16;
    int ball_x = 40;
    int ball_y = 16;
    int vector_x = 1;
    int vector_y = 1;
    int score1 = 0;
    int score2 = 0;
    char A, B, C;

    while (1) {
        if (scanf("%c%c%c", &A, &B, &C) == 3) {
            racket1_y += move_racket_1(A);
            racket2_y += move_racket_2(B);
        }

        vector_x = change_vector_ball_x(vector_x, ball_x, ball_y, racket1_y, racket2_y);
        vector_y = change_vector_ball_y(vector_y, ball_y);
        ball_x = move_ball_x(vector_x, ball_x);
        ball_y = move_ball_y(vector_y, ball_y);

        if (ball_x == 15) {
            racket1_y = 16;
            racket2_y = 16;
            vector_x = -vector_x;
            score2++;
            ball_x = 22;
            ball_y = 16;
            printf("%d %d", ball_x, ball_y);
        }
        if (ball_x == 65) {
            racket1_y = 16;
            racket2_y = 16;
            vector_x = -vector_x;
            score1++;
            ball_x = 58;
            ball_y = 16;
            printf("%d %d", ball_x, ball_y);
        }

        display(racket1_y, racket2_y, ball_x, ball_y, score1, score2);

        if (score1 == 21) {
            printf("First Wins!\n");
            break;
        } else if (score2 == 21) {
            printf("Second Wins!\n");
            break;
        }
    }
}
