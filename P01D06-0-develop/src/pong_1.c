#include <stdio.h>
#include <math.h>
//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
void display();
void display1();

int main(){
    int a, b;
    display(16, 010, 40, 9);
    return 0;
}

void display(int raket_1, int raket_2, int shar_x,int shar_y) {
    int k = 0; 
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if ((j == 20 && fabs(i - raket_1) <= 1) || (j == 60 && fabs(i - raket_2) <= 1)) { printf("|");}
            else {
                if (j == shar_x && i == shar_y ) { 
                    printf ( "*" );

                }
                else {
                    if (j == 40) {printf("|");}
                    else {printf(" ");}
                }
            }
        }
        printf("\n");

    }
}
