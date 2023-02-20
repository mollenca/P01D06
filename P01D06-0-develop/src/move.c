#include <stdio.h>
#define cross_and_toe_display
#define cross_pos1
#define cross_pos2
#define toe_pos
#define heiht_scring

void cross_and_toe_display(int cross_pos1, int cross_pros2, int toe_pos);
int main() {
    int cross_position1, cross_position2, toe_position;
        printf("Enter the \"X\" and \"O\" position:");

    if (scanf("%d%d%d", &cross_position1, &cross_position2, &toe_position) != 2 || cross_position1 < 0 || cross_position2 < 0 || toe_position < 0) {
        printf("Invalid position");
        return -1;
    }

    cross_and_toe_display(cross_position1, cross_position2, toe_position);
}

void cross_and_toe_display(int cross_pos1, int cross_pos2, int toe_pos) {
    char temp;
    switch (temp=getchar()){
        case 'a' : ((*croos_pos1-2) !=0) ? (*croos_pos1-=1) : *cross_pos1; break;
        case 'z' : ((*croos_pos1+2) !=heiht_scring-1) ? (*croos_pos1 += 1) : *cross_pos1; break;
        case 'k' : ((*croos_pos2-2) !=0) ? (*croos_pos2-=1) : *cross_pos2; break;
        case 'm' : ((*croos_pos2+2) !=heiht_scring-1) ? (*croos_pos2 += 1) : *cross_pos2; break;
        case ' ' : ((*toe_pos=0) !=heiht_scring=0) : *toe_pos; break;
}
