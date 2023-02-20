#include <math.h>
#include <stdio.h>
void MoveBall(int * vector_y, int * vector_x, int Width_Screen, int Length_Screen,int * Ball_x, int * Ball_y, int  Racket1_x, int  * Racket1_y, int  Racket2_x, int * Racket2_y){
if((*Ball_x == Racket1_x + 1 && (fabs(*Ball_y - *Racket1_y) <= 1))|| (*Ball_x == Racket2_x - 1 && (fabs(*Ball_y - *Racket2_y) <= 1))){
    *vector_x = -(*vector_x);
}
else if(*Ball_y == 1 || *Ball_y == Width_Screen - 1){
    *vector_y = -(*vector_y);
}
*Ball_x += *vector_x;
*Ball_y += *vector_y;
}
