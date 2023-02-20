#include <math.h>
#include <stdio.h>
int Score_Ball(int * Ball_x, int * Ball_y, int  Racket1_x, int  * Racket1_y, int  Racket2_x, int * Racket2_y, int * score1, int *score2, int *vector_x, int *vector_y){
    if (*Ball_x == Racket1_x) {
        *score2 += 1;
        
        *Ball_x = Racket1_x + 1;
        *Ball_y = *Racket2_y;
        *vector_x = -(*vector_x);
        

        
    }
    if (*Ball_x == Racket2_x) {
        *score1 += 1;
        *Ball_x = Racket2_x - 1;
        *Ball_y = *Racket1_y;
        *vector_x = -(*vector_x);
       
        
    }
    if (*score1 == 5){
        printf("First Wins!\n");
        return 1;
    }
       else if (*score1 == 5){
        printf("Second Wins!\n");
        return 1;
    }

    return 0;


}
